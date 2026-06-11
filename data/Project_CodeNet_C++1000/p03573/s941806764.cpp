//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a[3];
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]==a[1])
	cout<<a[2];
	else
	cout<<a[0];
	return 0;
}
