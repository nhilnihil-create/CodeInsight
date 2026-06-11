#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}

int main(){
  string s; cin >> s;
  int k = s.size();
  int rest = 15 - k;
  int w = 0;
  REP(i,k){ w += (s[i]=='o');}
  bool r = (rest+w>=8);
  cout << (r?"YES\n":"NO\n");

}