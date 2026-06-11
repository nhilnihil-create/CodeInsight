#include <bits/stdc++.h>
using namespace std;

signed main(){
	string C1, C2;
	cin >> C1 >> C2;
	swap(C2[0], C2[2]);
	if(C1 == C2){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}