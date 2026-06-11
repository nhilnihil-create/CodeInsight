#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int n=s.length();

	string t=s.substr(0, n-1), rt=t;
	reverse(rt.begin(), rt.end());
	if(s[n-1]!='0' || s[0]!='1' || s[n-2]!='1' || t!=rt){
		cout << -1 << endl;
		return 0;
	}

	int curr=1;
	for(int i=0; i<n-1; i++){
		cout << curr << " " << i+2 << endl;
		if(s[i]=='1') curr=i+2;
	}
	return 0;
}