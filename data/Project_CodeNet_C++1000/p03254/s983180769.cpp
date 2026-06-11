# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;

int main(){

  int n, candies;
  cin >> n >> candies;

  vector<int> children(n);
  for(int i=0; i<n; i++) cin >> children[i];
  sort(children.begin(), children.end());

  int ans = 0;
  for(int i=0; candies > 0; i++){
    candies -= children[i];
    if(candies >= 0) ans++;
    if(i == n-1 && candies >= 0){
      if(candies != 0) ans--;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}