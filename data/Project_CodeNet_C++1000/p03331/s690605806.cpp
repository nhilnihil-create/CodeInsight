#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,minsum=1000000;
  cin >> N;
  for(int i=1;i<N;i++){
    int A,B,sum=0;
    A=i,B=N-i;
    for(int j=0;j<8;j++){
      sum+=A%10;
      sum+=B%10;
      A/=10,B/=10;
    }
    minsum=min(minsum,sum);
  }
  cout << minsum << endl;
}