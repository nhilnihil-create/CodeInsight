#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
const double PI = 3.141592653589793;

int main(){
  int a[5];
  int b[5];
  rep(i, 5) cin >> a[i];
  rep(i, 5) b[i] = a[i]%10 == 0 ? 20 : a[i]%10;
  sort(b, b+5);
  int k;
  k = b[0] == 20 ? 10 : b[0];
  int ans = 0;
  rep(i, 5){
    a[i] = a[i] - a[i]%10 + (a[i]%10 == 0 ? 0 : 10);
    ans += a[i];
  }
  cout << ans - (10 - k)<<endl;
}