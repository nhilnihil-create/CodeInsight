#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,K,total;
  cin >> N >> K;
  total=1;
  for(int i=0;i<N;i++){
    if(total*2<=total+K)total*=2;
    else total+=K;
  }
  cout << total << endl;
}