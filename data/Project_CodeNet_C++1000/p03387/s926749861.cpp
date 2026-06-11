#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  
  int cnt = 0;
  int b = a[2]*2-a[1]-a[0];
  cnt += b / 2;
  if(b%2 != 0) cnt += 2;
  cout << cnt << endl;
  
  return 0;
}