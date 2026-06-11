#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  
  int a[N+1] = {0};
  int x;
  for (int i = 0; i < N; i++) {
    cin >> x;
    a[x]++;
  }
  
  sort(a, a+N+1);

  int ans = 0;
  for (int i = 0; i < N-K+1;i++) ans += a[i];
  cout << ans << endl;
}