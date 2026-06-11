#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb emplace_back
typedef pair<int,int> pi;

int a,b,c;

int main() {
	ios_base::sync_with_stdio(0); 
	cin.tie(0);
	cin >> a >> b >> c;
	if (a + b + 1 >= c) cout << b + c;
	else cout << b + (a + b + 1);
	return 0;
}
