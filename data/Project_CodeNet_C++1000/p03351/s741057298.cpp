#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int a, b, c, r;
  string ans = "No";
    cin >> a >> b >> c >> r;
    if(abs(a-c)<=r || (abs(b-c)<=r && abs(a-b)<=r)) ans = "Yes";
    cout << ans << endl;
}
