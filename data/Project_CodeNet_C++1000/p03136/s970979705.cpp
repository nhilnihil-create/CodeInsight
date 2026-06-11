#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MOD = 1e9+7;
using ll = long long;
using vi = vector<int>;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(x) x.begin(), x.end();
int main() {
  int a,ans=0,MAX=0;
  cin >> a;
  int b[a];
  rep(i,a){
    cin >> b[i];
    ans += b[i];
    MAX = max(MAX,b[i]);
    }
  if(ans<=(MAX*2))cout << "No";
  else cout << "Yes";
}