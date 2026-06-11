#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t N;
  cin >> N;
  int64_t Ans=0;
  for(int64_t p=1; p<sqrt(N)+1; p++){
    if((N-p)%p==0 && p<(N-p)/p){
      Ans+=(N-p)/p;
    }
  }
  cout << Ans << endl;
//  (N-p)/p=m && p<m
}