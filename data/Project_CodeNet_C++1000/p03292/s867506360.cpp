//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	ll a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cout<<a[2]-a[0];
	return 0;
}
