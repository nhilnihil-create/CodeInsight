#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
using namespace std;
typedef long long ll;
int main(){
  int n = 0;
  cin >> n;
  vector<int> num(n);
  for(int i = 0;i <= n - 1;i++){
    cin >> num[i];
  }
  vector<int> ans(n);
  bool can = true;
  for(int i = n - 1;i >= 0;i--){
    bool find = false;
    for(int j = num.size() - 1;j >= 0;j--){
      //cout << j << endl;
      if(num[j] == j + 1){
        find = true;
        ans[i] = j;
        num.erase(num.begin() + j);
        //cout<<1<<endl;
        break;
      }
    }
    if(!find)can = false;
  }
  if(can){
    for(int i = 0;i <= n - 1;i++){
      cout << ans[i] + 1 << endl;
      //cout<<0<<endl;
    }
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}