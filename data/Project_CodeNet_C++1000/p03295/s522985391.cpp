#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,m,aaa=99999999,ans=0;
  cin >> n >> m;
  vector<vector<long>> ab(m,vector<long>(2));
  for(long i=0;i<m;i++) cin >> ab[i][0] >> ab[i][1];
  sort(ab.begin(),ab.end());
  for(long i=m-1;i>=0;i--) if(ab[i][1]<=aaa) ans++,aaa=ab[i][0];
  cout << ans << endl;
}