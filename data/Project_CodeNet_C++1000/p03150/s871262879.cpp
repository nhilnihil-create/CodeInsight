#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
	string s;cin>>s;
	int n=s.size();
	bool chk=0;

	rep(i,8){
		string t=s.substr(0,i);
		string u=s.substr(n-(7-i),7-i);
		if(t+u=="keyence") chk=1;
	}
	if(chk) cout<<"YES"<<"\n";
	else cout<<"NO"<<"\n";
}