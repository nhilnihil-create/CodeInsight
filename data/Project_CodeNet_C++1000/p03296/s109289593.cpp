#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

int main(){
  int N; cin >> N;
  int a[N]; REP(i,N){cin>>a[i];}
  
  int r=0;
  for(int i=1;i<N;i++){
    if(a[i-1]==a[i]){
      a[i] = 1000;
      r++;
    }
  }
  cout << r << "\n";
}