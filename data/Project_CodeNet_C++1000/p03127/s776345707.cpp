#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
  if(b == 0)return a;
  return gcd(b,a %b);
}

int main(){
  int N;
  cin >> N;
  
  vector<int>HP(N);
  
  //Nは１からなので注意
  for(int i=0; i <N; i++){
    cin >> HP[i];
  }
  
  int minj = HP[0];
  
  for(int i= 1; i<N; i++){
    minj = gcd(minj,HP[i]);
  }
  cout << minj << endl;
}