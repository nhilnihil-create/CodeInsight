#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string s;
cin >> s;
int r=0,b=0;
rep(i,s.size()){
  if(s.at(i)=='0')r++;
  else b++;
}
int ans = min(r,b)*2;
cout << ans << endl;
}
