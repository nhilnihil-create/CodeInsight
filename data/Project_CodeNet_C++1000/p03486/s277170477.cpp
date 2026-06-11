#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

string s, t;

int main(void){
	cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());
	if(s < t) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
