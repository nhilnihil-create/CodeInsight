#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;

int main(){
  cin >> s;
  int n = s.size();
  string res = "NO";
  for(int left = 0; left <= n; left++){
    for(int right = left; right <= n; right++){
      string comp = s.substr(0, left) + s.substr(right);
      //cerr << comp << endl;
      if(comp == "keyence")
        res = "YES";
    }
  }
  cout << res << endl;
}