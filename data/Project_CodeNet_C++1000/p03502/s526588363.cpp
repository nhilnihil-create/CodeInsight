#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,total,K;
  cin >> N;
  K=N;
  total=0;
  for(int i=0;i<8;i++){
    total+=K%10;
    K/=10;
  }
  if(N%total==0)cout << "Yes" << endl;
  else cout << "No" << endl;
}