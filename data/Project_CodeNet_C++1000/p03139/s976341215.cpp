#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[114514],b[114514];
int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	cout<<min(a,b)<<' '<<max(a+b-n,0ll)<<endl;
	return 0;
}