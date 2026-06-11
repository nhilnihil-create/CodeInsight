#include<bits/stdc++.h>
#define ll long long 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define PI 3.1415926535897932384626433832795
#define F first
#define S second
#define V vector<ll>
#define ALL(sss) sss.begin(),sss.end()
#define arall(rr,n) rr+0,rr+n 
#define mod 1000000007
#define M 100
#define MAXN 1000000000

 
ll dp[101][100001];
int ans=INT_MAX;
ll n;
using namespace std;


void fileio(){
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
}

ll fun(ll v[], ll ind, ll w[], ll W){
    
    //if(fl)cout<<ind<<" "<<W<<endl;
    
    if(ind>=n)return 0;
    if(dp[ind][W]!=-1)return dp[ind][W];
    
    ll b=INT_MIN,a=fun(v,ind+1,w,W);
    if(W>=w[ind])
    b=v[ind]+fun(v,ind+1,w,W-w[ind]);

    dp[ind][W]=max(a,b);
   
    return dp[ind][W];
}


int main(){


     fileio();
    
   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  

    ll T=1,q;
    //cin>>T;
    while(T--){

        string a,b;cin>>a>>b;

       // memset(dp,-1,sizeof(dp));
        //ll ans=fun(v,st,w,W);
        ll n=a.length(),m=b.length();        
        ll dp[n][m],z=0;
        
      
        
        string ans;

        

        for (ll i = 0; i < n; ++i)
        {

            for(int j = 0; j < m; j++){

                if(!i || !j){
                    if(a[i]==b[j]){
                        dp[i][j]=1;
                    }
                    else dp[i][j]=0;
                    continue;
                }
                
                dp[i][j]=max({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                if(a[i]==b[j]){
                    dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
                    
                }
            }
        }
/*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<dp[i][j]<<" ";
            }cout<<endl;
        }*/

        for(int i=n-1;i>=0;){
            for(int j=m-1;j>=0;){
               // cout<<i<<" "<<j<<" "<<a[i]<<endl;
                if(i==0){
                    while(j>=0){
                        if(a[i]==b[j]){
                            ans=a[i]+ans;j--;
                            break;
                        }
                        j--;
                    }
                    i=-1;j=-1;
                    break;
                }
                if(j==0){
                    while(i>=0){
                        if(a[i]==b[j]){
                            ans=b[j]+ans;i--;
                            break;
                        }
                        i--;
                    }
                    i=-1;j=-1;
                    break;
                }

                if(a[i]==b[j]){
                    ans=a[i]+ans;
                    i--;j--;
                }
                else{
                    if(dp[i][j-1]>dp[i-1][j])j--;
                    else i--;
                }
            }
        }
        cout<<ans<<endl;
        
       // cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});

        // cout<<"Case #"<<q<<": "<<ans<<endl;
    }
    
//prllf("%.9f\n", x);//precision: 9 decimal places.

/*
    GP SUM:(
    (bk)-a)/k-1;//k is ratio and b is final term, a is initial term;

    Comparing two decimal numbers

    if (abs(a-b) < 1e-9) {
        // a and b are equal
    }
*/
    return 0;
}
