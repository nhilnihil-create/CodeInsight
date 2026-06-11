/*
  Reference:-
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forn1(i, n) for (int i = 1; i < int(n); i++)
#define PI pair<int,int>
#define all(vec) vec.begin(),vec.end()
ll mod=1000000007;
const int N=2e5 + 5;
void modify(int p, ll value,int n,ll t[]) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p] , t[p^1]);
}
ll query(int l, int r,int n,ll t[]) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) {res = max(res,t[l]);l++;}
    if (r&1) {r--;res = max(res,t[r]);}
  }
  return res;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll ar[n],br[n];
    forn(i,n)cin>>ar[i];
    forn(i,n)cin>>br[i];
    ll dp[2*(n+1)]={0};
    ll ans=0;
    forn(i,n){
        /*for(int j=0;j<ar[i];j++){
            dp[ar[i]]=max(dp[ar[i]],dp[j]+br[i]);
        }*/
        ll val=query(0,ar[i],n+1,dp);
        dp[n+1+ar[i]]=val+br[i];
        modify(ar[i],dp[n+1+ar[i]],n+1,dp);
        ans=max(ans,dp[n+1+ar[i]]);
        //cout<<ar[i]<<" "<<dp[ar[i]]<<" "<<val<<endl;
    }
    cout<<ans;

    return 0;
}
