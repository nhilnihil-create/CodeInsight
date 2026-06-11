#include <bits/stdc++.h>
using namespace std;
int main(){
 int N;
  cin >> N;
  int n = N;
  int goukei = 0;
  for(int i = 0; i < 9; i++){
    goukei += N % 10;
    N = N / 10;
  }
  if(n % goukei == 0){
    cout <<"Yes"<< endl; 
  }
  else{
    cout <<"No"<< endl;
  }
}