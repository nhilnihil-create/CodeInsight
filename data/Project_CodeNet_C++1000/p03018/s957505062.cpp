#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){
  
  string s;
  cin >> s;
  char last = 'A';
  int bc = 0;
  ll res = 0;
  for(char c : string(s.rbegin(),s.rend())){
    if(c == 'A'){
      int k = 0;
      if(last == 'B'){
        k = bc/2;
      }
      res += k;
      bc = k*2;
    }else{
      if(c != last){
        bc++;
        last = c;
      }else{
        bc = 1;
      }
    }
  }
  cout << res << "\n";





  return 0;
}