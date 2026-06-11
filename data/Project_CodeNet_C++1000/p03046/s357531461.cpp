//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <queue>

using namespace std;

const int nmax = 1e9 + 7;
const long long INF = 1e18;
const double PI = 2 * asin(1);
typedef long long ll;


int main(){
  int M, K; cin >> M >> K;

  int num = pow(2, M);

  if (M == 1){
    if (K == 0){
      cout << "0 0 1 1" << endl;
    }else{
      cout << -1 << endl;
    }
  }else{
    if (K < num){
      if (K == 0){
        for (int i = 0; i < 2 * num; i++){
          cout << i / 2;
          if (i != 2 * num - 1) cout << " ";
        }
        cout << endl;
      }else{
        cout << "0 " << K << " 0 ";
        for (int i = 1; i < num; i++){
          if (i != K){
            cout << i << " ";
          }
        }
        cout << K;
        for (int i = num - 1; i >= 1; i--){
          if (i != K){
            cout << " " << i;
          }
        }
        cout << endl;
        
      }
    }else{
      cout << -1 << endl;
    }
  }
    
  
  return 0;
}
