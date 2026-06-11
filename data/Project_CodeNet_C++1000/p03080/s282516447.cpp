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


int main(void) {
   ll N;
   cin>>N;
   string s;
   cin>>s;
   ll Num[2] = {};
   rep(i,0,N) {
      if (s[i]=='R') Num[0]++;
      else Num[1]++;
   }
   if (Num[0]>Num[1]) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
   return 0;
}