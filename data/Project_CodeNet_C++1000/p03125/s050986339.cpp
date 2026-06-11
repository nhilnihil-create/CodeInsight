#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;

int Solve(int x, int y){
  return y%x ? y-x : y+x;
}
int main(){
  int A,B; cin>>A>>B;
  cout<<Solve(A,B)<<endl;
}
  