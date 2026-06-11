#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {
	int ans=0;
	string s;
	cin>>s;
	for(int i=0;i<4;i++){
		if(s.substr(i,1)=="2")ans++;
	}
	cout<<ans<<endl;
		return 0;
}

