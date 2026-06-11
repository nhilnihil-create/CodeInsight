#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

vector<pair<ll, int>> prime_factorization(ll n) {
	vector<pair<ll, int>> res;
	for(ll i = 2; i * i <= n; i++){
		if(n % i) continue;
		res.emplace_back(i, 0);
		while(n % i == 0){
			n /= i;
			res.back().second++;
		}
	}
	if(n != 1) res.emplace_back(n, 1);
	return res;
}

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

int main() {
	int n;
	cin >> n;
	if(n==1) {
		cout << 0 << endl;
		return 0;
		
	}
	map<int, int> fac;
	for(int i = 1; i <= n; i++) {
		auto now = prime_factorization(i);
		rep(j, now.size()) {
			int key = now[j].first;
			int val = now[j].second;
			fac[key] += val;
		}
	}
	// for(auto t: fac) cout << t.first << " " << t.second << endl;
	// auto div75 = divisor(75);
	// for(auto t: div75) cout << t << endl;
	int ans = 0;
	vector<int> cnt;
	for(auto t: fac){
		cnt.push_back(t.second);
	}
	sort(all(cnt));
	for(int i = 0; i < cnt.size()-2; i++) {
		for(int j = i+1; j < cnt.size()-1; j++) {
			for(int k = j+1; k < cnt.size(); k++) {
				if(cnt[i]>=2 && cnt[j]>=4 && cnt[k]>=4) ans++;
				if(cnt[i]>=4 && cnt[j]>=2 && cnt[k]>=4) ans++;
				if(cnt[i]>=4 && cnt[j]>=4 && cnt[k]>=2) ans++;
			}
		}
	}
	for(int i = 0; i < cnt.size()-1; i++) {
		for(int j = i+1; j < cnt.size(); j++) {
			if(cnt[i]>=4 && cnt[j]>=14) ans++;
			if(cnt[i]>=14 && cnt[j]>=4) ans++;
		}
	}
	for(int i = 0; i < cnt.size()-1; i++) {
		for(int j = i+1; j < cnt.size(); j++) {
			if(cnt[i]>=2 && cnt[j]>=24) ans++;
			if(cnt[i]>=24 && cnt[j]>=2) ans++;
		}
	}
	for(int i = 0; i < cnt.size(); i++) {
		if(cnt[i]>=74) ans++;
	}
	cout << ans << endl;
	return 0;
}