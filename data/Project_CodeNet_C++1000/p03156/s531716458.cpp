#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;
  cin >> N >> A >> B;
  int P;
  int f=0;
  int s=0;
  int t=0;
  for(int i=0;i<N;i++){
    cin >> P;
    if(P<=A){
      f++;
    }else if(P>=B+1){
      t++;
    }else{
      s++;
    }
  }
  cout << min({f,s,t}) << endl;
  return 0;
}
