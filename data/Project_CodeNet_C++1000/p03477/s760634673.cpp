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
	if(a+b<c+d)
	cout<<"Right";
	else if(a+b>c+d)
	cout<<"Left";
	else
	cout<<"Balanced";
	return 0;
}
