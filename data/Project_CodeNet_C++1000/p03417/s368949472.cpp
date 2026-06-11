#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
static const int INF = 2000000000;


int main(){
  vector<ll> a(2);
  cin >> a[0] >> a[1];
  sort(ALL(a));
  ll ans;
  if (a[0] > 1){
    ans = (a[0] - 2) * (a[1] - 2);
  }else{
    if (a[1] > 1){
      ans = a[1] - 2;
    } else {
      ans = 1;
    }
  }
  cout << ans << endl;
}