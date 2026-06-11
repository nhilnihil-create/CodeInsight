#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,a,b,min,max;
  cin>>N>>a>>b;
  //最大
  if( a > b ){
    max = b;
  }
  if( a < b ){
    max = a;
  }
  //最少
  if( N >= a+b ){
    min = 0;
  }
  if( N < a+b ){
    min = ( a + b ) - N;
  }
  cout << max << " " << min << endl;
  return 0;
}