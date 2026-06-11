#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int N;
  cin >> N;
  vector <int> d(N);
  for (int i = 0; i < N; i++) cin >> d[i];
  sort(d.begin(), d.end());
  int ans = 0;
  int len = 0;
  for (int i = 0; i < N; i++) {
    if (len >= d[i]) continue;
    len = d[i];
    ans++;
  }
  cout << ans << endl;
  return 0;
}
