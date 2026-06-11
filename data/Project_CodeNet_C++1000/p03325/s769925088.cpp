#include <bits/stdc++.h>
using namespace std;


int main() {
  int N; cin >> N;
  int a[N];
  int ans = 0;
  for(int i = 0; i < N; i++){
    cin >> a[i];
    if(a[i]%2==0){
      while(a[i]%2==0){
        a[i] /= 2;
        ans++;
      }
    }
  }
  cout << ans << endl;
}
