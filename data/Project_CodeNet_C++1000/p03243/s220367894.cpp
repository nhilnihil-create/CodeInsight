#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  
  int n ;
  cin >> n ;
  
  if(n%111==0){
    cout << n << endl;
  }
  
  else{
    cout <<( n/111+1)*111 << endl;
  }
}