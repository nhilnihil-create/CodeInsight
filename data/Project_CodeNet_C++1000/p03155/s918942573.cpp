#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,h,w;
	cin>>n>>h>>w;
	n++;
	cout<<(n-h)*(n-w)<<endl;
	return 0;
}