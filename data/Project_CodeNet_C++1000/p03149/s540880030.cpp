#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> vec(4);
  cin >> vec.at(0);
  cin >> vec.at(1);
  cin >> vec.at(2);
  cin >> vec.at(3);
  sort(vec.begin(),vec.end());
  if(vec[0]==1&&vec[1]==4&&vec[2]==7&&vec[3]==9) cout << "YES" << endl;
  else cout << "NO" << endl;
}