#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,c;
  cin >> n >> m >> c;
  vector<int> b(m);
  int ans = 0;
  for(int i = 0; i < m; i++){
    cin >> b[i];
  }
  for(int i = 0; i < n; i++){
    vector<int> a(m);
    int sum = 0;
    for(int i = 0; i < m; i++){
      cin >> a[i];
      sum += a[i] * b[i];
    }
    if(sum + c > 0){
      ans++;
    }
  }
  cout << ans << endl;
}