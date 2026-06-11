#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;




int main() {
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i,n){
      cin >> vec.at(i);
  }
  sort(vec.begin(),vec.end());
  reverse(vec.begin(),vec.end());
  
  int Alice = 0;
  int Bob = 0;
  for(int i = 0; i < n; i++){
      if(i %2 == 0){
          Alice += vec.at(i);
      }else{
          Bob += vec.at(i);
      }
  }
  cout << Alice - Bob << endl;



}

