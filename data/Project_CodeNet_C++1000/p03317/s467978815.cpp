#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  int Sum=K, cnt=1;
  while(Sum < N){Sum += K-1;cnt++;}
  cout<<cnt<<endl;
  return 0;
}