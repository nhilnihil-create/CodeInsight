#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,f=0,g=1;
  cin >> N;
  for(int k=0;k<8;k++){
    	f+=N/g%10;
    	g*=10;
  }
  if(N%f==0) cout << "Yes" << endl; else cout << "No" << endl; 
}