#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b;
  	cin >> a >> b;
  	
  if ( (a + b) % 2 != 0){
    int avg = (a + b) / 2 + 1;
    cout << avg << endl;
  }else{
    int avg = (a + b) / 2;
    cout << avg << endl;
  }
  
  
  return 0;
}
