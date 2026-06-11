#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, x;
  string ans = "YES";
    cin >> a >> b >> x;
    if(a+b<x || x<a) ans="NO";
    cout << ans << endl;
}
