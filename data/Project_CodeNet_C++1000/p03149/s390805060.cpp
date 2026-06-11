#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N[4];
  cin >> N[0] >> N[1] >> N[2] >> N[3];
  sort(N,N+4);
  if(N[0] == 1 && N[1] == 4 && N[2] == 7 && N[3] == 9){
  	cout << "YES" << endl;
  }else{
  	cout << "NO" << endl;
  }
}