#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<long long> L(N+2);
  L[0]=2;
  L[1]=1;
  for(int i=0;i<N+1;i++){
    if(i<2){
      continue;
    }
    L[i]=L[i-1]+L[i-2];
  }
  cout << L[N] << endl;
}	