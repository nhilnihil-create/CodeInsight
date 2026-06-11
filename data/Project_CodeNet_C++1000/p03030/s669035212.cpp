#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  map<string,priority_queue<P>> p;
  rep(i,0,n) {
    string si; int pi;
    cin >> si >> pi;
    p[si].push(P(pi,i+1));
  }
  auto itr = p.begin();
  rep(i,0,p.size()) {
    while(!(itr->second.empty())) {
      P a = itr->second.top(); itr->second.pop();
      cout << a.second << endl;
    }
    itr++;
  }
  return 0;
}
