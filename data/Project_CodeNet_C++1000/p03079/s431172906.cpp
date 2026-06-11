#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  bool f = false;
  cin >> a >> b >> c;
  if (a==b && b==c && c==a) f = true;
  if (f) cout << "Yes" << endl;
  else cout << "No" << endl;
}