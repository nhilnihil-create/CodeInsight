#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int a,b;
	// nyuryoku
	cin >> a >> b;
	int ans = 0;
	if(a > b){
		ans += a;
		a--;
		ans += max(a,b);
	}else if(a == b){
		ans += 2*a;
	}else{
		ans += b;
		b--;
		ans += max(a,b);
	}
	// keisan
	cout << ans << endl;
	// syutsuryoku
}