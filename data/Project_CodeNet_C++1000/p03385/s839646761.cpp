#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  string S;
  cin >> S;
  map<char,int> m;
  m['a'] = 0;
  m['b'] = 0;
  m['c'] = 0;

  for(auto s: S){
    m[s] = 1;
  }
  bool flg = true;
  for(auto x: m){
    if(x.second == 0){
      flg = false;
      break;
    }
  }
  cout << (flg ? "Yes" : "No") << endl;
}
