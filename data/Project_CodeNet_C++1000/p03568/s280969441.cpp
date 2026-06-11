#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

//総数から奇数パターンの数を差し引く
int main(){
  long long N; cin >>N;
  long long num_even = 0;
  REP(i,N){
    long long a;
    cin >> a;
    if(a%2==0) num_even++;
  }
  long long r = pow(3,N) - pow(2,num_even);
  cout << r << "\n";
  
}