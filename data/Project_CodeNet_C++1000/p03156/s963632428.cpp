#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, a, b, var, count[3] = {0};
	cin >> n >> a >> b;
	while(n--) {
		cin >> var;
		if(var <= a)
			++count[0];
		else if(var <=b)
			++count[1];
		else
			++count[2];
	}
	sort(count, count + 3);
	cout << count[0];
	return 0;
}