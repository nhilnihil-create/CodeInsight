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
  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  int x[100], y[100];
  rep(i, n) cin >> x[i];
  rep(i, m) cin >> y[i];
  sort(x, x + n);
  sort(y, y + m);
  for(int i = -200; i < 200; i++){
    if(i <= X || Y < i) continue;
    if(i <= x[n-1]) continue;
    if(i > y[0]) continue;
    cout << "No War" <<endl;
    return 0;
  }
  cout << "War" << endl;
}