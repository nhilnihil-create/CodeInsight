#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  int a=0;
  if(N/100==1){
    a++;
  }
  if((N%100-N%10)/10==1){
    a++;
  }
  if(N%10==1){
    a++;
  }
  cout << a << endl;
}