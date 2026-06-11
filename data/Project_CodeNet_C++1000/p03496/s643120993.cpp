#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i,N) cin >> a[i];
  cout << N+N-2 << endl;
  if (*max_element(a.begin(),a.end()) >= abs(*min_element(a.begin(),a.end()))) {
    auto ix = max_element(a.begin(),a.end());
    rep(i,N){if (ix-a.begin()+1!=i+1)
      cout << ix-a.begin()+1 << ' ' << i+1 << endl;
    }
    rep2(i,1,N) {
      cout << i << ' ' << i+1 << endl;
    }
  }
  else {
    auto ix = min_element(a.begin(),a.end());
    rep(i,N){if (ix-a.begin()+1!=i+1)
      cout << ix-a.begin()+1 << ' ' << i+1 << endl;
    }
    for (int i=N;i>1;i--) {
      cout << i << ' ' << i-1 << endl;
    }
  }

} 