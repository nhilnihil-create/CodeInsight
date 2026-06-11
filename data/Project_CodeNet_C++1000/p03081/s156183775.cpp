#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;
// const long long MOD = (ll)1e9+7;
const long long MOD = (ll)1e6+3;
const long long MAX = (ll)170 * 80;

vector<pair<char,int>> vOp;
string s;

ll Check(ll start) {
   ll now = start;
   for(auto op: vOp) {
      if (s[now]!=op.first) continue;
      now += op.second;
      if (now<0) break;
      if (now>=s.size()) break;
   }
   return now;
}

int main(void) {
   ll N,Q;
   cin>>N>>Q;
   cin>>s;
   rep(i,0,Q) {
      char t;
      char d;
      cin>>t>>d;
      vOp.push_back(make_pair(t,d=='L'?-1:1));
   }
   ll ans0;
   int le = 0;
   int re = (int)s.size()-1;
   if (Check(le)>=0) ans0 = 0;
   else {
      while(1) {
         int ne = (le+re)/2;
         if (ne == le || ne == re) break;
         if (Check(ne)<0) le = ne;
         else re = ne;
      }
      if (Check(re)<0) ans0= re+1;
      else ans0 = le+1;
   }
   // cout<<ans0<<endl;
   ll ans1;
   le = 0;
   re = (int)s.size()-1;
   if (Check(re)<N) ans1 = 0;
   else {
      while(1) {
         int ne = (le+re)/2;
         if (ne == le || ne == re) break;
         if (Check(ne)>=N) re = ne;
         else le = ne;
      }
      if (Check(le)>=N) ans1= N-le;
      else ans1 = N-re;
   }
   // cout<<ans1<<endl;

   if (ans0+ans1>=N) cout<<0<<endl;
   else cout<<N-ans0-ans1<<endl;


   return 0;
}