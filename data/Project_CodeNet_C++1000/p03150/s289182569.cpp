#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0; i<=n; i++) {
		for(int j=0; j<=n; j++) {
			string t=s;
			if(t.erase(i,j)=="keyence") {
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	return 0;
}