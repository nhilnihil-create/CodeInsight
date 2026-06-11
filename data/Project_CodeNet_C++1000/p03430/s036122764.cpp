# include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

# define pb push_back
# define fr first
# define sc second
# define mk make_pair

using namespace std;

const long long linf = 1e18 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;

typedef long long ll;

string s;
int k, dp[301][301][301], u[301][301][301];

int calc(int l, int r, int k){
      if(k < 0) return -inf;
      if(l > r) return 0;
      if(l == r) return 1;
      if(u[l][r][k]) return dp[l][r][k];
      u[l][r][k] = 1;
      int &res = dp[l][r][k];
      res = max(calc(l + 1, r, k), calc(l, r - 1, k));
      if(s[l] == s[r])
            res = max(res, calc(l + 1, r - 1, k) + 2);
      else
            res = max(res, calc(l + 1, r - 1, k - 1) + 2);
      return res;
}

int main(){
      cin >> s >> k;
      s = ' ' + s;
      cout << calc(1, s.size() - 1, k) << endl;
}
