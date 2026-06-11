#include<bits/stdc++.h>
using namespace std;
 
int main() {
  string A;
  cin>>A;
  int cnt=0;
  if(A[0]=='o')cnt+=100;
  if(A[1]=='o')cnt+=100;
  if(A[2]=='o')cnt+=100;
  cout << 700+cnt;
}