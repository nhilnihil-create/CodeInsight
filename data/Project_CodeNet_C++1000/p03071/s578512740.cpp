#include<bits/stdc++.h>
using namespace std;
long long pi = 3.14159265358979323846264338327;
int a,b,ans=0;
int main() {
	cin >> a >> b;
	ans += max(a,b);
	ans += max(max(a,b)-1,min(a,b));
	cout << ans << endl;
 	return 0;
}
