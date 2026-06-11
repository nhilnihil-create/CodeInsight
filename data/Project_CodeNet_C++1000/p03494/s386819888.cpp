#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<long long> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  long long ans = 0;
  while(true){
    for(int i = 0; i < n; i++){
      if(a[i] % 2 != 0){
        cout << ans << endl;
        return 0;
      }
      a[i] /= 2;
    }
    ans++;
  }
}