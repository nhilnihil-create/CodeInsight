#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;
const double PI = acos(-1);

int main() {
string s;
  int k;
cin >> s >> k;
int cnt = 0;
rep(i,s.size()){
  if(s.at(i) !=  '1')break;
  cnt++;
}
if(cnt >= k) cout << 1 << endl;
else cout << s.at(cnt) << endl;
} 