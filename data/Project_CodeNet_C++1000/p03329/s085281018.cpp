#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int Ans=1000000;
  for(int i=0; i<=N; i++){
    int K=i;
    int L=N-i;
    int subAns=0;
    while(K>0){
      subAns+=K%6;
      K/=6;
    }
    while(L>0){
      subAns+=L%9;
      L/=9;
    }
    Ans=min(Ans, subAns);
  }
  cout << Ans << endl;
}