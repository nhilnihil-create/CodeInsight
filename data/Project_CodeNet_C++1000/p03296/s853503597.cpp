#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  int ans = 0;
  for (int i = 1; i < N; i++){
    if (a[i - 1] == a[i]){
      ans++;
      a[i] = 0;
    }
  }
  cout << ans;
}