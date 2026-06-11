#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int A=N;
  int sum=0;
  while(A>0){
    sum+= A%10;
    A/=10;}
  if(N%sum==0){
    cout << "Yes" <<endl;}
  else{
    cout << "No" << endl;}
}