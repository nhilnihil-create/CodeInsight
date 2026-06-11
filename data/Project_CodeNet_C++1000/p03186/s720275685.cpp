#include <bits/stdc++.h>
#define int long long
#define f first
#define s second
using namespace std;
int32_t main(){
	if(fopen("input.txt", "r"))
	freopen("input.txt", "r", stdin),
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int a,b,c;
	cin >> a >> b >> c;
	if(c>a+b){
		cout << a+2*b+1 << endl;
	}
	else cout << c+b << endl;
}
