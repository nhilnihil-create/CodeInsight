#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string s;
	cin>>s;
	s+='z';
	ll ans=0,cnt=0;
	for(ll i=0;i<s.size()-1;i++){
		if(s[i]=='A'){
			cnt++;
		}
		else if(s[i]=='B'&&s[i+1]=='C'){
			ans+=cnt;
			i++;
		}
		else{
			cnt=0;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}