#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,A=1,B=1;
  cin>>N;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    if(a%2==0){
      B*=2;
    }
    A*=3;
  }
  cout<<A-B<<endl;
}