#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B,C;
	cin >> A >> B >> C;
	int ans = B;
	if(A+B>=C){
	     ans+=C;
	}
	else{
	    // if(C-A+B)
	     ans+=(A+B)+1;
	}
	cout << ans;
	return 0;
}
