#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1000000001;
const ll MOD = 1000000007;

int main(){
  int a[3];
  rep(i, 3) cin >> a[i];
  int b[3];
  b[1] = abs(a[1] - a[0]);
  b[0] = abs(a[2] - a[0]);
  b[2] = abs(a[2] - a[1]);
  cout << min(b[0]+b[1], min(b[1]+b[2], b[0]+b[2])) <<endl;
}