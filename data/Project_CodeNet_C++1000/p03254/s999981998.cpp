#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, x; cin >> N>> x;
  int a[N];
  for(int i = 0; i<N; i++) cin >>a[i];
  sort(a, a+N);
  int ans = 0;
  for(int i = 0; i<N;i++){
    if(a[i]<=x){
      if(i!=N-1){
        x-=a[i];
        ans++;
      } else if(a[i]==x) ans++;
        }
    else {
      break;
    }
  }
  cout << ans << endl;
}
