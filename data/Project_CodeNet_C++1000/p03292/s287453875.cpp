#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  vector<int> vec(3);

  for (int i = 0; i < 3; i++){
    cin >> vec.at(i);
  }

  sort(vec.begin(),vec.end());

  int sum = 0;
  for (int i = 0; i < 2; i++){
    sum += vec.at(i + 1) - vec.at(i);
  }

  cout << sum << endl;
}