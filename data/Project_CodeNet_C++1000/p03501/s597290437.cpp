#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	int ans=n*a;
	if(ans>b) ans=b;
	cout << ans << endl;
}
