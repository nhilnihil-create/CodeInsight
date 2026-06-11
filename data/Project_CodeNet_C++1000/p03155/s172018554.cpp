#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,h,w;
	cin>>n>>h>>w;
	cout<<((n+1)-h)*((n+1)-w)<<endl;
	return 0;
}
