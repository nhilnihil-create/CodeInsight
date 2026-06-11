#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  int a, b, c, d;
  string ans;
    cin >> a >> b >> c >> d;
    a += b;
    c += d;
      (a==c) ? ans="Balanced": (a<c)? ans="Right": ans="Left";
    cout << ans << endl;
}