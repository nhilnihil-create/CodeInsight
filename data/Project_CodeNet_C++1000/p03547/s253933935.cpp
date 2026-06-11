#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string a, b, ans;
    cin >> a >> b;
      a<=b ? (a==b ? ans="=" :ans="<") : ans=">";
    cout << ans << endl;

}