//Date and time of submission: 
 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	string s;
	cin>>s;
	ll cnt=0;
	for(char ch: s)
	cnt+=(ch=='o');
	cout<<700+(cnt*100);
	return 0;
}
