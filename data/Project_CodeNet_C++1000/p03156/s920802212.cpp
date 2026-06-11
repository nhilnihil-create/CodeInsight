#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  int C=0;
  int D=0;
  int E=0;
  vector<int>P(N);
  for(int i=0;i<N;i++){
    cin >> P[i];
    if(P[i]<=A){
      C++;
    }
    else if(P[i]>A&&P[i]<=B){
      D++;
    }
    else{
      E++;
    }
  }
  cout << min(min(C,D),E) << endl;
}