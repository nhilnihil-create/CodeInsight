#include <iostream>
#include <vector>
#include <map>
using namespace std; using P=pair<int,int>; using ll=long long; template<class T> using vec=vector<T>;
int main() {
	int n; cin>>n;
	map<int,int> mp;
	for(int i=0;i<n;i++) {
		int a; cin>>a; mp[a]++;
	}
	int m; cin>>m;
	for(int i=0;i<m;i++) {
		int a; cin>>a; mp[a]--;
	}
	bool ok=true;
	for(P x:mp) {
		if (x.second<0) ok=false;
	}
	if (ok) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}