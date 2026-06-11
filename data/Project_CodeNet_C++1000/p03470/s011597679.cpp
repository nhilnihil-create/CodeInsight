#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int ans = 1;
  int num;
  cin >> num;
  vector <int> mochis(num);
  for(int i = 0; i < num; i++)
    cin >> mochis.at(i);
  sort(mochis.begin(), mochis.end());
  //reverse(mochis.begin(), mochis.end());
  for(int i = 1; i < num; i++){
    if(mochis.at(i - 1) != mochis.at(i))
      ans++;
  }
  cout << ans << endl;
  
  
}