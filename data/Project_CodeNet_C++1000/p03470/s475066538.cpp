#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
  int a;
  cin >> a;
  vector <int> ans(a);
  for(int i = 0;i<a;i++){
      cin >> ans.at(i);
  }
  sort(ans.begin(),ans.end());
  int sum = 0;
  for(int i = 0;i<a-1;i++){
    if(ans.at(i)!=ans.at(i+1))sum++;
  }
      cout << sum+1;
}