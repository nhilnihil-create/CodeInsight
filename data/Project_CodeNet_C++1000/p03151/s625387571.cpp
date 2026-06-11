#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  int N; cin >> N;
  int sum = 0, sum1 = 0;
  vector<int> a(N), b(N);
  for(int i = 0; i < N; i++){
    cin >> a[i]; sum += a[i];
  }
  for(int i = 0; i < N; i++){
    cin >> b[i]; sum1 += b[i];
  }
  if(sum < sum1){
    cout << -1 << endl;
    return 0;
  }
  sum = 0;
  int c = 0;
  vector<int> sa(N);
  for(int i = 0; i < N; i++){
    sa[i] = a[i] - b[i];
    if(sa[i] < 0) {
      sum += sa[i]; c++;
    } 
  }
  sort(sa.begin(), sa.end()); reverse(sa.begin(), sa.end());
  int i = 0;
  while(sum < 0){
    sum += sa[i];
    i++;
  }
  cout << c + i << endl;
}