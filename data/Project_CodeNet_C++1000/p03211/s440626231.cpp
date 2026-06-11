#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;

int main(){
  string s;
  cin >> s;
  int ans = INF;
  for(int i = 0; i < int(s.size() - 2); i++){
    int a = s[i]-48, b = s[i+1]-48, c = s[i+2]-48;
    int k = 100 * a + 10 * b + c;
    ans = min(ans, abs(k - 753));
  }
  cout << ans << endl;
}