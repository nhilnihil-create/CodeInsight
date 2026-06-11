#include<iostream>
#include<set>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N;
  cin >> N;

  set<string> d;
  string w, prev, ans = "Yes";
  cin >> prev;
  d.insert(prev);
  rep(i,1,N-1) {
    cin >> w;
    if (d.count(w) != 0 || prev[prev.size()-1] != w[0]) {
      ans = "No";
    }
    prev = w;
    d.insert(prev);
  }

  cout << ans << endl;
  return 0;
}
