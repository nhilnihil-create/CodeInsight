#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A;
  cin>>N>>A;
  if((N+A)%2==1){
    cout << (N+A)/2+1;
    return 0;
  }
  cout << (N+A)/2;
}