#define rep(i, a, b) for(int i = a; i < (int)(b); i++)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
template<class T> inline void chmax(T &a, const T &b) {if(a < b) a = b;}
template<class T> inline void chmin(T &a, const T &b) {if(a > b) a = b;}
const long long INF = 1LL<<60;
const long long MOD = (ll)1e9+7;
const long long MAX = (ll)170 * 80;


int main(void) {
   string S;
   cin>>S;
   ll a[2] = {};
   rep(i,0,S.size()) {
      if (S[i]=='o') a[0]++;
      else a[1]++;
   }
   // cout<<a[0]<<" "<<a[1]<<endl;
   if (a[0] + (15-a[1]-a[0]) >= 8) cout<<"YES"<<endl;
   else cout<<"NO"<<endl;

   


   return 0;
}