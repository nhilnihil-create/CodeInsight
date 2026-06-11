#include <bits/stdc++.h>
using namespace std;


int main(){
  int N;
  cin >> N;
  
  if(N%10==0){
    cout << 10 << endl;
  }
 
  
  else if(N%10!=0){
    int a=N/1000000;
    int b=(N%1000000)/100000;
    int c=(N%100000)/10000;
    int d=(N%10000)/1000;
    int e=(N%1000)/100;
    int f=(N%100)/10;
    int g=N%10;
    
    cout << a+b+c+d+e+f+g << endl;
  }
}
    