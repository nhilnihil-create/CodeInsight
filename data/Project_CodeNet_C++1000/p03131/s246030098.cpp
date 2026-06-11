#include<iostream>
using namespace std;
int main(){
  long k,a,b;
  cin >> k >> a >> b;
  if(b-a <= 2){
    cout << 1+k << endl;
    return 0;
  }

  cout << (b-a)*((k-a+1L)/2L)+a+((k-a+1L)%2L) << endl;
  return 0;
}