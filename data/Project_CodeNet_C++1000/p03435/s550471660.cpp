#include <bits/stdc++.h>
using namespace std;

bool check(int a,int b,int c, int d){
  if(a+d==b+c)
    return true;
  else
    return false;
}

int main() {
  vector<vector<int>> data(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> data.at(i).at(j);
    }
  }
  if(!check(data.at(0).at(0),data.at(0).at(1),data.at(1).at(0),data.at(1).at(1)))
  cout << "No" << endl;
  else if(!check(data.at(0).at(1),data.at(0).at(2),data.at(1).at(1),data.at(1).at(2)))
  cout << "No" << endl;
  else if(!check(data.at(1).at(0),data.at(1).at(1),data.at(2).at(0),data.at(2).at(1)))
  cout << "No" << endl;
  else if(!check(data.at(1).at(1),data.at(1).at(2),data.at(2).at(1),data.at(2).at(2)))
  cout << "No" << endl;
  else
  cout << "Yes" << endl;
}

