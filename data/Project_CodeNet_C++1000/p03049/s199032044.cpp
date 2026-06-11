#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	vector<string>s;
	for(ll i=0;i<n;i++){
		string t;
		cin>>t;
		s.push_back(t);
	}
	ll ab,b,a,ba;
	ab=b=a=ba=0;
	for(ll i=0;i<n;i++){
		string now=s[i];
		for(ll j=1;j<now.size();j++){
			if(now[j-1]=='A'&&now[j]=='B'){
				ab++;
			}
		}
		if(now[0]=='B'&&now[now.size()-1]=='A'){
			ba++;
		}
		else if(now[now.size()-1]=='A'){
			a++;
		}
		else if(now[0]=='B'){
			b++;
		}
	}
	ll ans=ab;
	if(ba>0){
		ans+=ba-1;
		if(a>0){
			ans++;
			a--;
		}
		if(b>0){
			ans++;
			b--;
		}
		ans+=min(a,b);
	}
	else{
		if(a>0&&b>0){
			ans+=min(a,b);
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}