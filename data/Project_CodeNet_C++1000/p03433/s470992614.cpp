//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll n,a;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>n>>a;
	if((n%500)<=a)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
