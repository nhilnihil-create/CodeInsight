#include<bits/stdc++.h>
using namespace std;

vector<int> num;

int mochictrl(int x) {
  if(x == 0) return 0;
  if(num[x] == num[x - 1]) num.erase(num.begin() + x);
  return mochictrl(x - 1);
}

int main() {
  int temp, mochis;
  cin >> mochis;
  for(int i = 0; i < mochis; i++ ) {
    cin >> temp;
    num.push_back(temp);
  }
  sort(num.begin(),num.end());
  mochictrl(mochis);
  cout << num.size() << endl;
  //cout << "↓配列" << endl;
  //for(auto& x:num) {
  //  cout << x << endl;
  //}
}

