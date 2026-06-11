#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;
const ll MOD=1e9+7;

ll n,z,w;
ll a[2001];
ll dp[2001][2];
int flag[2001][2];


ll ddpp(int i,int b){
    if(flag[i][b]){
        return dp[i][b];
    }
    else{
        flag[i][b]=1;
        if(b==0){
            if (i==n){
                dp[i][b]=abs(a[n]-a[n-1]);
                if (i==1){
                  dp[i][b]=abs(a[n]-w);
                  return abs(a[n]-w);
                }
                return abs(a[n]-a[n-1]);
            }
            else{
                ll ans1=0;
                for (int x=i+1;x<n+1;x++){
                    ans1=max(ans1,ddpp(x,1-b));
                }
                if (i==1){
                    //cout<<abs(w-a[n])<<" "<<1<<endl;
                    ans1=max(ans1,abs(w-a[n]));
                }
                else{
                ans1=max(ans1,abs(a[i-1]-a[n]));}
                dp[i][b]=ans1;
                return ans1;
            }
        }
        else{
            if (i==n){
                if (i==1){
                  dp[i][b]=abs(a[n]-z);
                  return abs(a[n]-z);
                }
                dp[i][b]=abs(a[n]-a[n-1]);
                //cout<<dp[i][b]<<" "<<12<<endl;
                return dp[i][b];
            }
            else{
                ll ans1=10000*MOD+MOD+MOD;
                for (int x=i+1;x<n+1;x++){
                    ans1=min(ans1,ddpp(x,1-b));
                }
                if (i==1){
                    ans1=min(ans1,abs(z-a[n]));
                }
                else{
                ans1=min(ans1,abs(a[i-1]-a[n]));}
                dp[i][b]=ans1;
                return ans1;
            }
        }
    }

}

int main() {
    cin>>n>>z>>w;
    rep(i,n){
        cin>>a[i+1];
    }
    ddpp(1,0);
    cout<<dp[1][0]<<endl;
  /*rep(i,n){
rep(j,2){
cout<<dp[i+1][j]<<" ";
}
    cout<<endl;}*/
    

    return 0;
}
