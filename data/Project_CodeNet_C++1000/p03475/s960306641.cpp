#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using P = pair<int, int>;
const int inf=1e9+7;
const ll INF=1e18;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  int n;
  cin>>n;
  vin c(n-1),s(n-1),f(n-1);
  rep(i,0,n-1){
     cin>>c[i]>>s[i]>>f[i];    //i から　間　start 周期
  }
  ///////// station  0index
  rep(i,0,n){//i駅から 0
                int ans=0;
                if(i==n-1) {
                  cout<<0<<endl;
                  break;
                }
                else{
                  ans+=s[i];  
                  ans+=c[i];//i+1に到着
                          rep(j,1,n-i-1 ){
                              if(ans<s[i+j]){
                               ans=s[i+j];
                               ans+=c[i+j];//i+2に到着
                              }
                              else{
                               while(ans%f[i+j]!=0){
                                ans++; 
                               }
                                ans+=c[i+j];
                              }
                               //cout<<i<<i+j<<ans<<endl;
                          }
                     
                }
                 cout<<ans<<endl;
  }
}







