#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];

  int last_a = 0;
  int first_b = 0;
  int both_ba = 0;
  int ab = 0;
  rep(i, n){
    int siz = s[i].size();
    if(s[i][0] == 'B' && s[i][siz-1] == 'A') both_ba++;
    else if (s[i][0] == 'B') first_b++;
    else if (s[i][siz-1] == 'A') last_a++;
    rep(j, siz-1){
      if(s[i][j] == 'A' && s[i][j+1] == 'B'){
        ab++;
      }
    }
  }

  if(both_ba == 0){
    ab += min(last_a, first_b);
  }
  else{
    if(last_a + first_b > 0){
      ab += both_ba + min(last_a, first_b);
    }
    else{
      ab += both_ba - 1;
    }
  }
  cout << ab << endl;
  return 0;
}
