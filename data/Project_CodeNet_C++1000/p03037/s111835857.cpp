#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<int>L(M);
  vector<int>R(M);
  int ans=0;
  int count=0;
  for(int i=0;i<M;i++){
    cin >> L[i] >> R[i];
    if(i==0){
      ans=L[0];
      count=R[0];
    }
    else{
      ans=max(ans,L[i]);
      count=min(count,R[i]);
    }
  }
  if(ans>count){
    cout << 0 << endl;
  }
  else{
    cout << count-ans+1 << endl;
  }
}