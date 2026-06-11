// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	int len = 1;
	vector<int> comps;
	vector<bool> tp;
	for(int i = 1; i < n; i++) {
		if(s[i] != s[i-1]) {
			tp.push_back( (s[i]-'0') ^ 1 );
			comps.push_back(len);
			len = 1;
		}
		else len++;
	}

	comps.push_back(len);
	tp.push_back((s[(int)s.length()-1]-'0'));

	int ans = 0;

	int go = 0;
	int ptr = 0;
	int sum = 0;

	for(int i = 0; i < comps.size(); i++) {
		if(tp[i]==0) go++;
		sum += comps[i];
		while(go>k) {
			if(tp[ptr]==0) go--;
			sum -= comps[ptr];
			ptr++;
		}
		if(tp[i]) {
			ans=max(ans, sum);
		}
	}

	if(go<=k) ans=max(ans, sum);

	for(int i = 0; i < tp.size(); i++) tp[i] = !tp[i];

	go = 0;
	ptr = 0;
	sum = 0;
	
	k--;

	if(k==0) {
		for(int i = 0; i < comps.size(); i++) {
			ans=max(ans, comps[i]);
		}
		cout << ans;
		exit(0);
	}

	for(int i = 0; i < comps.size(); i++) {
		if(tp[i]==0) go++;
		sum += comps[i];
		while(go>k) {
			if(tp[ptr]==0) go--;
			sum -= comps[ptr];
			ptr++;
		}
		if(tp[i]) {
			ans=max(ans, sum);
		}
	}

	if(go <= k) ans=max(ans, sum);

	cout << ans;

	return 0;
}
