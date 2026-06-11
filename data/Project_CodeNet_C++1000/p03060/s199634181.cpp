#include <iostream>
#include <string>

using namespace std;

int v[21];

int main() {

  int n, l, ans = 0;
  cin >> n;
  for(int i = 1;i <= n;i++){
    cin >> v[i];
  }
  for(int i = 1;i <= n;i++){
    cin >> l;
    if(v[i] > l){
      ans += v[i] - l;
    }
  }
  cout << ans;
  return 0;
}
