#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main()
{
  int n,x;
  cin >> n >> x;
  vector<int> m(n);
  for(int i=0;i<n;i++) cin >> m[i];

  sort(m.begin(),m.end());

  int sum = 0;
  for(int i=0;i<n;i++) sum += m[i];

  x -= sum;
  int ans = n + x/m[0];

  cout << ans << endl;
}
