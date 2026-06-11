#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,C1=0,C2=0,C3=0;
  cin >> N >> A >> B;
  for(int i=0;i<N;i++){
    int P;
    cin >> P;
    if(P<=A){
      C1++;
    }
    else if(P<=B){
      C2++;
    }
    else{
      C3++;
    }
  }
  cout << min({C1,C2,C3}) << endl;
}