#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n,m,c; cin >> n >> m >> c;
  vector<int> b(m);
  int ans = 0;
  int sum = 0;
  for(int i = 0; i < m; i++){
    cin >> b.at(i);
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      int a; cin >> a;
      sum += a * b.at(j);
    }
    if(sum + c > 0) ans++;
    sum = 0;
  }
  cout << ans;
}