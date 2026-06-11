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
  int n, m;
  cin >> n >> m;
  P p[100000];
  rep(i, m){
    int a, b;
    cin >> a >> b;
    p[i] = P(b, a);
  }
  sort(p, p + m);
  
  int last = -1;
  int ans = 0;
  
  rep(i, m){
    if(p[i].second > last){
      ans++;
      last = p[i].first - 1;
    }
  }
  cout << ans <<endl;
}