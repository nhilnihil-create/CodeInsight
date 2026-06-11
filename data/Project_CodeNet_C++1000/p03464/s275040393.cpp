#include <iostream>
#define llint long long
#define mod 1000000007

using namespace  std;

llint n;
llint a[100005];

int main(void)
{
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];

  llint lb = 2, ub = 2;
  for(int i = n; i >= 1; i--){
    lb = (lb+a[i]-1)/a[i]*a[i];
    ub = ub/a[i]*a[i];
    if(lb > ub){
      cout << -1 << endl;
      return 0;
    }
    ub += a[i]-1;
  }
  cout << lb << " " << ub << endl;

  return 0;
}
