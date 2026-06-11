#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int>data(9);
  for(int i = 0;i < 9;i++){
    cin >> data.at(i);
  }
  int d1,d2,d3;
  d1 = data.at(0)+data.at(4)+data.at(8);
  d2 = data.at(1)+data.at(5)+data.at(6);
  d3 = data.at(2)+data.at(3)+data.at(7);
  if(d1 == d2 && d2 == d3){
    cout << "Yes" << endl;
  }
  else cout << "No" << endl;
}
