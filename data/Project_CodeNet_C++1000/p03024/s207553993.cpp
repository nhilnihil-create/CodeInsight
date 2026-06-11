#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  string s;
  cin >> s;
  int n = s.size();

  int cnt = 0;
  rep(i,n) if(s[i] == 'o') cnt++;
  if(cnt+15-n>=8) cout << "YES" << endl;
  else cout << "NO" << endl;
}
