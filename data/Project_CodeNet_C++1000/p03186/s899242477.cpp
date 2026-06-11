///WRONG LIFE
///DIE(RETRY)
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include "bits/stdc++.h"
using namespace std;

#define pb push_back
#define F first
#define S second
#define f(i,a,b)  for(int i = a; i < b; i++)
#define endl '\n'

using ll = long long;
using db = long double;
using row = vector<int>;
using ii = pair<int, int>;

const int N = 2e5 + 5, M = 26, A = 6561, LG = 19, MOD = 998244353;
const int BLOCK = 500;
const long double EPS = 1e-7;
using pii = pair<int,int>;

int main(){
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(0);
  cin.tie(0);
#endif // ONLINE_JUDGE

  int A,B,C;
  cin >> A >> B >> C;

  int ans = min(A,C);
  C-=ans;
  A-=ans;
  ans += min(B,C)*2;
  ans += (B - min(B,C));
  if(B<C)ans++;
  cout<<ans<<'\n';

    return 0;
}
