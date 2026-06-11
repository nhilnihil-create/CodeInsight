#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> ans(3);
  for(int i=0;i<3;i++)cin >> ans.at(i);
  sort(ans.begin(),ans.end());
  int ae =0;
  ae += ans.at(2) - ans.at(0) ;
  cout << ae;
}
