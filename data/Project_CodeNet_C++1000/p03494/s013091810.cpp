#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  int ans = 0;
  for(int i = 0; ; i++){
    for(int j = 0; j < n; j++){
      if(a[j] % 2 != 0){
        cout << ans << endl;
        return 0;
      }else{
        a[j] /= 2;
      }
    }
    ans++;
  }
}