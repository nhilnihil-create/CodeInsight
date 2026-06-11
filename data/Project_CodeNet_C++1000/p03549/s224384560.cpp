#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
int main() {
  int N = 0,M = 0;
  cin >> N >> M;
  if(M == 1){
    cout << (1900 * M + 100 * (N - M)) * 2;
  }
  if(M == 2){
    cout << (1900 * M + 100 * (N - M)) * 4;
  }
  if(M == 3){
    cout << (1900 * M + 100 * (N - M)) * 8;
  }
  if(M == 4){
    cout << (1900 * M + 100 * (N - M)) * 16;
  }
  if(M == 5){
    cout << (1900 * M + 100 * (N - M)) * 32;
  }
}
      
  
  