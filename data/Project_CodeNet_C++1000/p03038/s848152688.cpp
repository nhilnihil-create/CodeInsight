#include <bits/stdc++.h>
using namespace std;


int main(){
  int N, M;
  cin >> N >> M;
  
  int a[N];
  pair<int, int> cb[M];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < M; i++) {
    int b, c;
    cin >> b >> c;
    cb[i] = {c, b};
  }
  
  sort(a, a+N);
  sort(cb, cb+M, greater<pair<int, int>>());
  
  int aI = 0;
  for (int i = 0; i < M; i++) {
    while (cb[i].second>0 && aI<N) {
      if(cb[i].first>a[aI]) {
        a[aI] = cb[i].first;
        aI++;
        cb[i].second--;
      } else {
        break;
      }
    }
  }
  
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    ans += (long long) a[i];
  }
  
  cout << ans << endl;
  
}