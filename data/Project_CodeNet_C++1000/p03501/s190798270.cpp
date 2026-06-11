#include <bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C;
  	int X,Y,ans;
	cin >> A >> B >> C;
	X = A*B;
  	Y = C;
  	if(X >= Y){
     ans = Y;
    }else{
      ans = X;
    }
	cout << ans << endl;
	return 0;
}