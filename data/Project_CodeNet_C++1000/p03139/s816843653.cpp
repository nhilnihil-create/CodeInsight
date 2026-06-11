#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,A,B;cin>>N>>A>>B;
  printf("%d %d",min(A,B),max(A+B-N,0));
}