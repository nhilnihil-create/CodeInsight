//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a,b,c,d;
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	cin>>a>>b>>c>>d;
	if(abs(a-c)<=d)
	cout<<"Yes";
	else if(abs(a-b)<=d&&abs(b-c)<=d)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
