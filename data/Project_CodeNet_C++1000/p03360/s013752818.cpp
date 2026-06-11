#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int a,b,c,k;
  cin>>a>>b>>c>>k;
  int m=max({a,b,c});
  cout << (pow(2, k)-1)*m+a+b+c << endl;
}
