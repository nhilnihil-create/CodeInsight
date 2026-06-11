#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N;
  cin >> N;
  long long H, a[N], b[N];
  long long max_a=0;
  cin >> H;
  for (int i = 0; i < N; i++){
    cin >> a[i] >> b[i];
    if (max_a < a[i]){
      max_a = a[i];
    }
  }

  sort(b, b+N);

  int ans = 0;
  for (int i = N-1; i >= 0; i--){
    if (max_a > b[i]) break;
    H -= b[i];
    ans++;
    if (H <= 0) break;
  }

  if (H > 0){
    long long n = H / max_a;
    if (H%max_a != 0){
      n += 1;
    }
    ans += n;
  }

  printf("%d\n", ans);
  
}
