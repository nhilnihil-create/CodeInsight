#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  int sum =0;
  int num =N;
  while(num>0){
    int n = num %10;
    sum += n;
    num = num/10;
  }
  if(N%sum == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}