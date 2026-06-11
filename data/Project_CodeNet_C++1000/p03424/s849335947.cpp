#include <bits/stdc++.h>
using namespace std;

int main() {
				// *constraint*
  int N;    	// 1<=N<=100
  char S;		// Si は'P' or 'W' or 'G' or 'Y'
  				// Si = 'p',Sj = 'W',Sk = 'G' を満たすi,j,kが存在する
  cin  >> N;
  bool hasY = false;
  int i = 0;
  while (i < N) {
    cin >> S;
    if(S == 'Y'){
      hasY = true;
      break;
    }
    i ++;
  }

  if(hasY){
    cout << "Four" << endl;
  }else{
    cout << "Three" << endl;
  }

}
