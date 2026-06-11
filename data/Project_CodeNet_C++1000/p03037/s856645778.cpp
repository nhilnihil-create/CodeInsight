#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	IOS;
	int n,m;
	cin >> n >> m;
	int l,r;
	int under=1,upper=n;
	for(int i=0;i<m;i++){
		cin >> l >> r;
		under = max(under,l);
		upper = min(upper,r);
	}
	if(under > upper){
		cout << '0' << endl;
	}else{
		cout << upper - under + 1 << endl;
	}
}