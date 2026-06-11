#include <bits/stdc++.h>
using namespace std;

#define sz(x) int(x.size())
#define Task "abc"
#define For(i, a, b) for(int i = (a), _b = (b); i <= b; ++i)
#define All(x) (x).begin(), (x).end()
#define mp make_pair

typedef long long ll;

const int maxn = 2e3 + 10;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;

int n;
bitset<maxn * maxn> f[2];
int a[maxn];

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
//  freopen(Task".inp", "r", stdin);  freopen(Task".out", "w", stdout);
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i){
    cin >> a[i];
    sum = sum + a[i];
  }
  if (n == 1) return cout << a[1], 0;
  f[0].set(0, 1);
  for (int i = 1; i <= n; ++i){
    int st = i % 2;
    f[st] = (f[st ^ 1] | (f[st ^ 1] << a[i]) );
  }

  for (int i = sum / 2 + (sum % 2); ; ++i){
    if ( (f[n % 2] >> i).test(0)) return cout << i, 0;
  }
}


