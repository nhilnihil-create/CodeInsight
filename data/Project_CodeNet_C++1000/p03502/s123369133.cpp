#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin>>N;
  int cnt = 0;
  M = N;
  while(M>=1){
    cnt = cnt + M % 10;
    M /= 10;
  }
  //cout << cnt << endl;
  if(N % cnt == 0){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
