#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m = 0;

  cin >> n;
  if((n/100)==1){
    m++;
  }
  if((n-(n/100)*100)/10==1){
    m++;
  }
  if((n-(n/10)*10)==1){
    m++;
  }
  
  cout << m << endl;
}