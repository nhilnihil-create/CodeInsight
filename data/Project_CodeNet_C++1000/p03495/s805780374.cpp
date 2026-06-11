#include <bits/stdc++.h>
using namespace std;
int cnt[200010];
main(void){
  int n,k;cin >> n >> k;
  for(int i=0;i<n;i++){
    int a;cin >> a;
    cnt[a-1]++;
  }
  sort(cnt,cnt+n);
  int ans=0;
  for(int i=0;i<n-k;i++) ans+=cnt[i];
  cout << ans << endl;
  return 0;
}