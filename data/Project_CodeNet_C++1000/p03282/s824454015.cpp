#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
using LP = pair<int, int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const double PI=3.14159265358979323846;

int mod = 1e9+7;
const long long INF = 1LL<<60;


int main(){
  string str;
  cin >> str;
  ll K;
  cin >> K;

  for(int i=0; i<min((ll)str.size(), K); i++){
    if(str[i] != '1'){
      cout << str[i] << endl;
      return 0;
    }
  }

  cout << 1 << endl;

  return 0;
}
