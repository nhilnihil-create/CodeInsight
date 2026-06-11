#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, c;
    cin >> a >> b >> c;
  string ans="Yes";
    if(a+b<c) ans = "No";
  cout << ans << endl;
}
