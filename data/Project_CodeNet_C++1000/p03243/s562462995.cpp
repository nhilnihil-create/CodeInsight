#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
const ll INF = 1001001001;
const ll MOD = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  int a[10] = {111, 222,333,444,555,666,777,888,999};
  cout << *lower_bound(a, a + 10, n) << endl;
}