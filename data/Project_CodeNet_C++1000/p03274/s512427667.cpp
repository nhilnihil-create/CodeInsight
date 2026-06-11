#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define m1(x) memset(x,-1,sizeof(x))
const int INF = 1001001001;
const ll MOD = 1e9 + 7;
const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027019385211055596446229489549303819644288109756659334461284756482337867831652712019091456485669234603486104543266482133936072602491412737245870066063155881748815209209628292540917153643678925903600113305305488204665213841469519415116094330572703657595919530921861173819326117931051185480744623799;

int n, k;

int main(){
  cin >> n >> k;
  int x[100000];
  rep(i, n) cin >> x[i];
  int ans = INF;
  for(int i = 0; i < n - k + 1; i++){
    if(x[i] < 0 && x[i+k-1] > 0){
      ans = min(ans, min(2 * x[i+k-1]-x[i], x[i+k-1] - 2 * x[i]));
    }else{
      if(x[i+k-1]<=0) ans = min(ans, -1*x[i]);
      else ans = min(ans, x[i+k-1]);
    }
  }
  cout << ans <<endl;
}