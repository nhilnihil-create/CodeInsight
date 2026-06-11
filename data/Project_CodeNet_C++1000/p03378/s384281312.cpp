#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X;
  cin >> N >> M >> X;
  int A=0,B=0;
  for(int i=0;i<M;i++){
    int C;
    cin >> C;
    if(C<X){
      A++;
    }
    else{
      B++;
    }
  }
  cout << min(A,B) << endl;
}