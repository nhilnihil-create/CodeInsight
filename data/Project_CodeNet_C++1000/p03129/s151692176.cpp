#include<iostream>
using namespace std;
int main(){
  int n,k;
  cin >> n >> k;
  if(k<=(n+1)/2){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}