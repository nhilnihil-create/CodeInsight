#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<int,string>;

int main() {
  int x;
  cin >> x;
  while(true){
    for(int i =1; i <=1000;i++){
      for(int j = 2; j <= 10; j++){
        if(pow(i,j) == x){
          cout << x << endl;
          return 0;
        }
      }
    }
    x--;
  }
 } 
