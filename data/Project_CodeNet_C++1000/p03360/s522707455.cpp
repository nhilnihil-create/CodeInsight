#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
  vector<int> a(3);
  int k;
  int ans=0;
  cin >> a[0] >> a[1] >> a[2] >> k;
  sort(a.begin(),a.end());
  for(int i=0;i<k;i++){
    a[2] = a[2]*2;
  }
  ans = a[0]+a[1]+a[2];
  cout << ans << endl;
      return 0;
}
