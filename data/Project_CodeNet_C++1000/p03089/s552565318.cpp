#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  deque<int> a;
  rep(i,n) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  deque<int> b;
  while(a.size()!=0) {
    bool ok=false;
    for(int i=a.size()-1; i>=0; i--) {
      if(a[i]==i+1) {
        a.erase(a.begin()+i);
        b.push_front(i+1);
        ok=true;
        break;
      }
    }
    if(!ok) {
      cout << -1 << endl;
      return 0;
    }
  }
  for(auto p : b) cout << p << endl;
  return 0;
}