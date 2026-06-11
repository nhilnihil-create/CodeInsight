#include <bits/stdc++.h>
using namespace std;

int main(){
  set<int> x;
  set<int> y={1,4,7,9};
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  x.insert(a);
  x.insert(b);
  x.insert(c);
  x.insert(d);
  if(x==y) cout << "YES" << endl;
  else cout << "NO" << endl;
}
  