#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 0, s, nv;
	cin >> s;
	nv = s;
	set<int> st;
	st.insert(nv);
	while(1){
		if(nv%2 == 0) nv/=2;
		else nv = 3*nv + 1;
		ans++;
		if(st.find(nv) != st.end()) break;
		st.insert(nv);
	}
	cout << ans + 1;
	return 0;
}