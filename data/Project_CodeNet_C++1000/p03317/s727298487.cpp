#include<iostream>
using namespace std;
int main(){
  int n, k;
  cin >> n >> k;
  for(int i = 0; i < n; i++){
    int a;
    cin >> a;
  }
  if((n-1) % (k-1) != 0){
    cout << ((n-1) / (k-1)) + 1<< endl;
  } 
  else{
    cout << (n-1) / (k-1) << endl;
  }
  return 0;
}
