#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define modulo 1000000007
#define fast_io ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int main(){
	fast_io;
	string s;
	cin>>s;
	ll temp=0,ans;
	for (int i = 0; i < s.size(); ++i){
		temp+=(s[i]-'0');
	}
	ans=9*(s.size()-1)+((s[0]-'0')-1);
	ans=max(ans,temp);
	cout<<ans<<"\n";
	return 0;
}