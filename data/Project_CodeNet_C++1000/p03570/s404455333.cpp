#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s; cin >> s;
	ll h[s.size()] = {1 << (s[0] - 'a')};
	for(ll i = 1; i < s.size(); ++i) h[i] = (h[i - 1] ^ (1 << (s[i] - 'a')));
	map<ll, ll> M;
	M.insert(pair<ll, ll>(0, 0));
	M.insert(pair<ll, ll>(1 << (s[0] - 'a'), 1));
	for(ll i = 1; i < s.size(); ++i){
		ll mindp = 1145148931919810;
		for(ll j = 0; j <= 26; ++j){
			auto ite = M.find(h[i] ^ (j == 26 ? 0 : (1 << j)));
			if(ite != M.end()){
				mindp = min<ll>(mindp, ite->second);
			}
		}
		auto ite = M.find(h[i]);
		if(ite == M.end()) M.insert(pair<ll, ll>(h[i], mindp + 1));
		else ite->second = min<ll>(ite->second, mindp + 1);
	}
	cout << (h[s.size() - 1] ? M.find(h[s.size() - 1])->second : 1) << endl;
	return 0;
}