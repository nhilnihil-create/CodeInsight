#include <bits/stdc++.h>

using namespace std;

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define ar array

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int > pii;
const ll MOD =1e9+7;

void solve(){
	string s,t ; cin >> s >> t;
	map<char,char>mp1,mp2;
	for(int i = 0; i < sz(s); ++i){
		if(mp1.count(s[i]) && mp1[s[i]]!= t[i]){
			cout<<"No";return;
		}
		if(mp2.count(t[i]) && mp2[t[i]]!= s[i]){
			cout<<"No";return;
		}
		mp1[s[i]]=t[i];
		mp2[t[i]]=s[i];
	}
	cout<<"Yes";
}
int main(){
	int t=1;
	//cin >> t;
	while(t--){
		solve();
		cout <<'\n';
	}
}
