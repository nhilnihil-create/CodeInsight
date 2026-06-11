#include<bits/stdc++.h>
using namespace std;
 
int main() {
  string A;
  cin>>A;
  int cnt=0;
  if(A[0]=='1')cnt++;
  if(A[1]=='1')cnt++;
  if(A[2]=='1')cnt++;
  cout << cnt;
}