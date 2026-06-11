#include<bits/stdc++.h>
using namespace std;
#define INFTY 10000000000
typedef long long int ll;
const int MOD=1000000007;
using Graph = vector<vector<int>>;
using ipair = pair<ll,ll>;
bool operator< (const ipair a, const ipair b){return a.first < b.first;};
#define rep(i,n) for (int i = 0; i < (n); ++i)
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
int main(){
  
  int n;cin>>n;
  vector<ll> ans(1000005,INFTY);
  ans[0] = 0;
  rep(i,100003){
    ans[i+1] = min(ans[i+1],ans[i]+1);
    int l=6;
    while(i+l<=n){
      ans[i+l] = min(ans[i+l],ans[i]+1);
      l *= 6;
    }
    l=9;
    while(i+l<=n){
      ans[i+l] = min(ans[i+l],ans[i]+1);
      l *= 9;
    }   
  }
  cout<<ans[n]<<endl;
  return 0;
}