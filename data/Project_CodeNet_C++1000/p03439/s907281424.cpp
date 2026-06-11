#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string V="Vacant",Ma="Male",Fe="Female";

int main(){
  int N;cin >> N;
  int U=0,L=N;
  vector<int> T(N+1,0);
  cout << 0 << endl;
  string S;
  cin >> S;
  if(S==V){
    return 0;
  }else if(S==Ma){
    T[0] = 1;
    T[N] = 1;
  }else{
    T[0] = 2;
    T[N] = 2;
  }
  while(true){
    int M = (U+L)/2;
    cout << M << endl;
    cin >> S;
    if(S==V){
      return 0;
    }else if(S==Ma){
      T[M] = 1;
    }else{
      T[M] = 2;
    }
    if((T[U]==T[M]&&(M-U)%2==1)||(T[U]!=T[M]&&(M-U)%2==0)){
      L=M;
    }else{
      U=M;
    }
  }
}