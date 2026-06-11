#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,w;
  cin >> n;
  set<int> a;
  rep(i,n){
    cin >> w;
    a.insert(w);
  }
  cout <<a.size()<<endl;
}