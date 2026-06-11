#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;

// const ll DIV = (ll)8e3+7;
const ll MAXN = (ll)8e3+7;

bool dp[MAXN*4+1];

void Update(ll v) {
   bool dp1[MAXN*4+1];
   rep(i,0,MAXN*4+1) dp1[i] = false;
   rep(i,0,MAXN*4+1) {
      if (dp[i]) {
         if (i+v< MAXN*4+1 && i+v>=0) dp1[i+v] = true;
         if (i-v< MAXN*4+1 && i-v>=0) dp1[i-v] = true;
      }
   }
   swap(dp,dp1);
   return;
}


int main(void) {
   string S;
   cin>>S;
   ll x,y;
   cin>>x>>y;
   vector<ll> vx[2];
   ll now = 0;
   ll dir = 0;
   rep(i,0,S.size()) {
      if(S[i] == 'F') now++;
      if (S[i] == 'T' || i == S.size()-1) {
         vx[dir].push_back(now);
         dir++;
         dir = dir%2;
         now = 0;
      }
   }

   if (!vx[0].size()) {
      if (x!=0) {
         cout<<"No"<<endl;
         return 0;
      }
   } else {
      auto itr = vx[0].begin();
      x -= vx[0][0];
      vx[0].erase(itr);
   }

   // for (auto el: vx[0]) cout<<el<<endl;
   // for (auto el: vx[1]) cout<<el<<endl;
   // cout<<x<<" "<<y<<endl;
   bool ans = true;

   rep(i,0,MAXN*4+1) dp[i] = false;
   dp[MAXN*2] = true;
   for (auto el: vx[0]) Update(el);
   if (!dp[MAXN*2+x]) ans = false;

   rep(i,0,MAXN*4+1) dp[i] = false;
   dp[MAXN*2] = true;
   for (auto el: vx[1]) Update(el);
   if (!dp[MAXN*2+y]) ans = false;

   if (ans) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;

   return 0;
}

