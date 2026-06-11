#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  vector<int> ans(5);
  int a;
  for(int i=0;i<5;i++)cin >> ans.at(i);
  cin >> a;
  sort(ans.begin(),ans.end());
  if(abs(ans.at(0)-ans.at(4))>a)cout << ":(";
  else cout << "Yay!";
}