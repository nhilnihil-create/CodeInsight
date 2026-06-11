#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repx(i,x,n) for(int i=x; i<(int)(n);i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    int n,k;
    cin>>n>>k;
    vin h(n),dp(n,1001001001);
    rep(i,n) cin>>h[i];
    dp[0]=0;
   
    rep(i,n){
        repx(j,1,k+1){
            
            if(i+j>n-1) break;
            dp[i+j]=min(dp[i+j],dp[i]+abs(h[i+j]-h[i]));
        }
    }
   cout<<dp[n-1]<<endl;

}
