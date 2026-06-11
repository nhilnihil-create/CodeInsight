#include<bits/stdc++.h>
    using namespace std;
  #define int long long int
    #define endl "\n"
    #define MOD 1000000007
    #define mod 1000000007
    #define M 1000000007
    
    #define pb push_back
    #define take(a,b,c) for(int b=0;b<c;b++) cin>>a[b]
  //  #define mp make_pair
  #define boost ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);  
  #define mx 400005
  #define fiint(a,b) memset(a,b,sizeof(a))  
  #define bitcount __builtin_popcount
  #define fori(i,a,b) for(int i=a;i<b;i++)
  #define ford(i,a,b) for(int i=a;i>=b;i--)
  #define debug(x) cout<<x<<endl;
  #define cases(t) int t; cin>>t; while(t--)
  #define inf1 INT_MAX
  #define all(a) a.begin(),a.end()
  #define vec vector<int>
  #define pii pair<int,int>
  #define plii pair<int,int>
  #define pint pair<int,int>
  #define ff first
  #define ss second
  #define lb lower_bound
  #define ub upper_bound
  #define bs binary_search
  #define sz(x) (int)x.size()
#define PI                    3.14159265359

bool prime[10000001];

void sieveFunction(int maxLimit){
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1]=false;
    for(int i=2; maxLimit >= i ; i++){
        if(prime[i]){
            for(int j=2*i ; maxLimit >= j ; j+=i)
                prime[j]=false;
        }
    }
}



	double ex[305][305][305];
	double p[305][305][305];
signed  main() 
{ 
	int n;cin>>n;
	vector<int> a(n + 1 ),cnt(4);
	fori(i,1,n+1){cin>>a[i];     cnt[a[i]]++; }
	//cout<<"Sds"<<endl;
	p[cnt[1]][cnt[2]][cnt[3]]=1;
	for(int c = n ; c>=0 ; c--)
			for(int  b= n ; b >= 0 ; b-- )
				for(int a = n ; a >= 0 ;a--  )
					{	

						if(a+c+b > n) continue;
						if(a==0 && b==0 && c==0)
							continue;
						double pw = (double)(n - (a+b+c) )/n;
						double ew = pw / (1 - pw)  + 1;
						ex [a][b][c] += ew *  p[a][b][c]; 

						if(c!=0)
							{ 
								double temp = (double) c/(a+b+c); 
								p[a][b+1][c-1]  += p[a][b][c] * temp; 
								ex[a][b+1][c-1] += ex [a][b][c] * temp;
							
							}
						if(b!=0)
							{ 
								double temp = (double) b/(a+b+c); 
								p[a+1][b-1][c]  += p[a][b][c] * temp;  
							    ex[a+1][b-1][c] += ex [a][b][c] * temp;            
			                }
						if(a!=0)
							{ 
								double temp = (double) a/(a+b+c); 
								p[a-1][b][c]  += p[a][b][c] * temp;         
								ex[a-1][b][c] += ex [a][b][c] * temp;

							}
						
					}

		printf("%.10lf\n", ex[0][0][0]); 	
}




 
