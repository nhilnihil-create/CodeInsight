#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
  int n, a;
  cin >> n;
  set<int> d;
  rep(i,n){
    cin >> a;
    d.insert(a);
  }
  cout << d.size() << endl;
  return 0;
}
