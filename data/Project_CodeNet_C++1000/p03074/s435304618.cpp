#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define pii pair<int, int>
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define Debug(X) cout << #X << " = " << X << '\n'
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef unsigned long long ull;
typedef long long ll;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f;

char s[maxn];
pair<int,int> sto[maxn];
int n, k, m;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);
  cin >> n >> k;
  cin >> s + 1;
  int l = 1, r = 1;
  if (s[1] == '0') sto[++m] = mp(1, 1);

  for (; l <= n; ++l){
    if (s[l] == '0') continue;
    r = l;
    while (r + 1 <= n && s[r + 1] == '1') ++r;
    sto[++m] = mp(l, r);
    l = r;
  }

  if (s[n] == '0') sto[++m] = mp(n, n);
  int ma = 0;
  for (int i = 1; i <= m; ++i){
    ma = max(ma, sto[min(i + k, m)].second - sto[i].first + 1);
  }
  cout << ma;
return 0;
}

