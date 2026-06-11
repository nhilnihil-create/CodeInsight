#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  int u1000, u100, u10, u1;
  u1000 = N / 1000;
  u100 = (N % 1000) / 100;
  u10 = (N % 100) / 10;
  u1 = N % 10;
  if(u100 == u10) {
    if(u1000 == u100 || u10 == u1){
    	cout << "Yes" << endl;
    }
    else {
    	cout << "No" << endl;
    }
  }
  else {
  	cout << "No" << endl;
  }

}