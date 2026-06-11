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
  int n;
  int seki = 1;
  int wa = 0;
  REP(i,4){
    cin >> n;
    seki *= n;
    wa += n;
  }
  bool r = ( (seki==9*4*7) && (wa==1+9+7+4) );
  cout << (r? "YES\n":"NO\n");
}