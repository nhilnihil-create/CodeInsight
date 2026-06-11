#include<bits/stdc++.h>
#define int long long int
#define fr(i,x,y) for(int i=x;i<y;i++)
#define f(n) for(int i=0;i<n;i++)
#define ff(m) for(int j=0;j<m;j++)
#define F(x) for(auto it=x.begin();it!=x.end();it++)
#define in insert
#define pb push_back
#define pi pair<int,int>
#define si(x) x->second
#define fi(x) x->first
#define start_routine cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); int begtime = clock();
#define end_routine int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0;
#define FILEIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
using namespace std;
void print(int a[],int n){f(n){cout<<a[i]<<" ";}cout<<endl;}
int m(int x){return x%1000000007;} 
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}
int p(int a,int b){if(b==0)return 1;int t=p(a,b/2); if(b%2==0)return t*t; else return a*t*t; } 
//strlen(s.c_str());  set <int, greater<int>> s; numeric_limits<double>::max()
//---------------------------------------------------------------------------------------------------------------------------------------------
 


signed main(){
	//FILEIO
	int a,b,c;
	cin>>a>>b>>c;
	if(a==b && b==c){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	

	
	
	






	return 0;
}

