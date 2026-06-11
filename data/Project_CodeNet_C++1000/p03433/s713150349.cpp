#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A;
  bool flag;
  int num;
  cin >> N >> A;

  num = N % 500;
  if(A >= num){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  } 
}