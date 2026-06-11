#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
const double PI = acos(-1);  

int main(){
  string s; cin >> s;
  int ans=0;
  for(int i=0; i<s.size(); i++)
    if(s[i]=='+') ans += 1;
    else ans -= 1;
  cout << ans << endl;
}
