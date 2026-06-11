#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B,allsum=0;
  cin >> N >> A >> B;
  for(int i=0;i<N;i++){
    int sum=0;
    int C=i+1;
    while(C>0){
      sum+=C%10;
      C/=10;
    }
    if(A<=sum && sum<=B){
      allsum+=i+1;
    }
  }
  cout << allsum << endl;
}