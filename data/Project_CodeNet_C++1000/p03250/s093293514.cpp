#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> ans(3);
  for(int i=0;i<3;i++)cin >> ans.at(i);
  sort(ans.begin(),ans.end());
  cout << ans.at(0) + ans.at(1) +ans.at(2)*10;
}
