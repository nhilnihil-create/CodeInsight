#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
  string S;  cin >> S;
  int N = (int) S.size();
  
  for(int k = N; k >= N/2; k--){
    bool flag = true;
    if( N-k > k-1){ continue;}
    for(int j = N-k; j < k-1; j++){
      if(S[j] != S[j+1]){ flag = false; break;}}
    if(flag){ cout << k << endl; return 0;}
  }
  cout << N/2 << endl; return 0;}