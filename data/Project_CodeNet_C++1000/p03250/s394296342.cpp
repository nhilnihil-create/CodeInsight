#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  vector<int> vec(3);
  for (int i = 0; i < vec.size(); i++){
    cin >> vec.at(i);
  }
  
  sort(vec.begin(), vec.end());

  cout << vec.at(2) * 10 + vec.at(1) + vec.at(0) <<endl;
}