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
  int n;
  cin >> n;
  double ans = 0;
  rep(i, n){
    double x;
    string u;
    cin >> x >> u;
    if(u == "JPY") ans += x;
    else ans += x * 380000;
  }
  cout << ans <<endl;
}