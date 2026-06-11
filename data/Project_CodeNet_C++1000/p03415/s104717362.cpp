#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  vector<string> vec(3);

  for (int i = 0; i < vec.size(); i++){
    cin >> vec.at(i);
  }

  for (int i = 0; i < vec.size(); i++){
    cout << vec.at(i).at(i);
  }

  cout << "" << endl;
}