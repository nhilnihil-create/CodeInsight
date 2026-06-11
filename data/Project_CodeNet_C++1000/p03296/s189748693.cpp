#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,ans = 0;
  cin >> n;
  vector<int>data(n);
  for(int i = 0;i < n;i++){
    cin >> data[i];
  }
  for(int i = 0;i < n-1;i++){
    if(data[i] == data[i+1]){
      ans++;
      i++;
    }
  }
  cout << ans << endl;
}
