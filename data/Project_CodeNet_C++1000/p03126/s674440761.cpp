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
  int n, m;
  cin >> n >> m;
  bool loved[30];
  fill(loved, loved + 30, true);
  rep(i, n){
    int k;
    cin >> k;
    bool checked[30];
    fill(checked, checked + 30, false);
    rep(i, k){
      int a;
      cin >> a;
      checked[a-1] = true;
    }
    rep(i, m){
      if(!checked[i]) loved[i] = false;
    }
  }
  cout <<  count(loved, loved + m, true) <<endl;;
}
  