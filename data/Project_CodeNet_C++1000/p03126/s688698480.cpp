#include <iostream>
#include <string>

using namespace std;

int v[31];

int main() {

  int n, m, l, ans = 0, hol, horse;
  cin >> n >> m;
  for(int i = 1;i <= n;i++){
    cin >> hol;
    for(int j = 1;j <= hol;j++){
      cin >> horse;
      v[horse]++;
    }
  }
  for(int i = 1;i <= m;i++){
    if(v[i] == n){
      ans++;
    }
  }
  cout << ans;
  return 0;
}
