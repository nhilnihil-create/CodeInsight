#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,k,x,y,n=1;
  cin>>N>>k;
  for(int i=0;i<N;i++){
    x=2*n;
    y=n+k;
    if(x>y){
      n=y;
    }
    else{
      n=x;
    }
  }
  cout << n << endl;
}