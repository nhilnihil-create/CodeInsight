#include <bits/stdc++.h>
using namespace std;
int main(){
  int A, B, C;
  cin >> A >> B >> C;
  vector<int> vec = {A, B, C};
  sort(vec.begin(),vec.end());
  if (vec.at(0)==vec.at(2)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}