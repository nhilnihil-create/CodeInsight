//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>n;
	if(n&1)
	cout<<2*n;
	else
	cout<<n;
	return 0;
}
