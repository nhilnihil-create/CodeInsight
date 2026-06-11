#include<iostream>
using namespace std;
 
int main(){
  int n, a;
  cin >> n >> a;
  int s = 0;
  while(1){
    if(n - 500 * s < 0){
      break;
    }
    s++;
  }
  if(n - 500 * (s - 1) > a){
    cout <<"No";
  }
  else{
    cout << "Yes";
  }
}