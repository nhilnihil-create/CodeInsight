#include <bits/stdc++.h>
using namespace std;

int main() {
  long n,c,ans;
  cin >> n >> c;
  vector<long> tvt(50,-1);
  vector<long> tvch(50,-1);
  vector<vector<long>> v(n,vector<long>(3));
  for(long i=0;i<n;i++) cin >> v[i][0] >> v[i][1] >> v[i][2];

  sort(v.begin(),v.end());
  for(long i=0;i<n;i++) {
    for(long j=0;true;j++) {
      if(tvt[j]<v[i][0]) {
        tvt[j]=v[i][1];
        tvch[j]=v[i][2];
        break;
      } else if(tvch[j]==v[i][2]){
        tvt[j]=v[i][1];
        tvch[j]=v[i][2];
        break;
      }
    }
  }
  for(long i=0;true;i++) {
    if(tvt[i]==-1) {
      ans=i;
      break;
    }
  }
  cout << ans << endl;
}