#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

Int sum(vector<Int> &a, Int l, Int r){
	return a[r] - (l-1 >= 0 ? a[l-1] : 0);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n;
	string s;
	cin >> n >> s;

	vector<Int> a(n);
	for(Int i=0; i<n; ++i)
		if(s[i] == 'M')
			a[i] = 1;
	for(Int i=1; i<n; ++i)
		a[i] += a[i-1];

	vector<Int> di, ci;
	for(Int i=0; i<n; ++i){
		if(s[i] == 'D') di.push_back(i);
		if(s[i] == 'C') ci.push_back(i);
	}

	Int q; cin >> q;
	while(q--){
		Int k; cin >> k;
		if(di.size() == 0){
			cout << 0 << "\n";
			continue;
		}
		Int ans = 0, tmp = 0;
		size_t j = 0;
		queue<Int> q;
		while(j < ci.size() && ci[j] < di[0]) ++j;
		while(j < ci.size() && ci[j] < di[0]+k){
			q.push(ci[j]);
			tmp += sum(a, di[0], ci[j]);
			++j;
		}
		ans += tmp;
		for(size_t i=1; i<di.size(); ++i){
			while(!q.empty() && q.front() < di[i]){
				Int p = q.front(); q.pop();
				tmp -= sum(a, di[i-1], p);
			}
			tmp -= q.size() * sum(a, di[i-1], di[i]);
//			cout << i << " " << di[i] << " " << tmp << "\n";
			while(j < ci.size() && ci[j] < di[i]) ++j;
			while(j < ci.size() && ci[j] < di[i]+k){
				q.push(ci[j]);
				tmp += sum(a, di[i], ci[j]);
				++j;
			}
			ans += tmp;
		}
		cout << ans << "\n";
	}
}