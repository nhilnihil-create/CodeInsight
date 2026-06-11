#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N,M;
  cin >> N >> M;
  if(N == 1){
	  if(M != 1){
		  cout << M-2 << endl;
		  return 0;
	  }
	  else{
		  cout << 1 << endl;
		  return 0;
	  }
  }
  else if(M == 1){
	  if(N != 1){
		  cout << N-2 << endl;
		  return 0;
	  }
	  else{
		  cout << 1 << endl;
		  return 0;
	  }
  }
  else{
  cout << (N-2)*(M-2) << endl;
}
}
