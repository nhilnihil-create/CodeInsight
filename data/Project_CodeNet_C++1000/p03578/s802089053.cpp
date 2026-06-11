#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e9;
const ll MOD = 1000000007;
const double pi = 3.141592653589793238;

// a と b の最大公約数を返す関数
long long GCD(long long a, long long b) { if (b == 0) {return a;} else {return GCD(b, a % b);} }
// a と b の最小公倍数を返す関数
long long LCM(long long a, long long b) { return a/GCD(a,b)*b; }

template<class T> inline bool chmin(T& a, T b) { if (a > b) {a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) {a = b; return true; } return false; }

int main() {
  int N; cin >> N;
  unordered_map<int, int> p;
  for(int i = 0; i < N; i++) {
    int a; cin >> a;
    if(p.count(a) > 0) {
      p.at(a)++;
    } else {
      p.emplace(a, 1);
    }
  }

  int M; cin >> M;
  if(M > N) {
    cout << "NO"<< endl;
    return 0;
  }

  for(int i = 0; i < M; i++) {
    int a; cin >> a;
    if(p.count(a) == 0) {
      cout << "NO"<< endl;
      return 0;
    } else {
      p.at(a)--;
      if(p.at(a) < 0) {
        cout << "NO"<< endl;
        return 0;
      }
    }
  }


  cout << "YES" << endl;
}
