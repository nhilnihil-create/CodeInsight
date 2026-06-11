#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<char> A(N);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  int a1=0;
  int a2=0;
  int a3=0;
  int a4=0;
  int ans=0;
  for(int i=0;i<N;i++){
    if(A[i]=='G'){
      a1=1;
    }
    else if(A[i]=='W'){
      a2=1;
    }
    else if(A[i]=='Y'){
      a3=1;
    }
    else{
      a4=1;
    }
  }
  if(a1!=0){
    ans++;
  }
  if(a2!=0){
    ans++;
  }
  if(a3!=0){
    ans++;
  }
  if(a4!=0){
    ans++;
  }
  if(ans==3){
    cout << "Three" << endl;
  }
  else{
    cout << "Four" << endl;
  }
}