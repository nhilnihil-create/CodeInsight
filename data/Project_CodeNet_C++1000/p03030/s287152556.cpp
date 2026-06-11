#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n;
	cin>>n;
	vector<tuple<string,ll,ll>>q;
	for(ll i=0;i<n;i++){
		string s;ll x;
		cin>>s>>x;
		q.push_back(make_tuple(s,-x,i+1));
	}
	sort(q.begin(),q.end());
	for(ll i=0;i<n;i++){
		cout << get<2>(q[i])<<endl;
	}
	// your code goes here
	return 0;
}