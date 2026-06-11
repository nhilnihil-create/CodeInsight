#include <bits/stdc++.h>


using namespace std;

#define ll long long


int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N,K;
	cin >> N >> K;
	unordered_map<int,int> cnt;
	int diff=0;
	for(int i=0;i<N;i++) {
		int x;cin >> x;
		if(cnt[x]==0) diff++;
		cnt[x]++;
	}
	
	vector<int> v;
	for(auto p : cnt) {
		v.push_back(p.second);
	}
	sort(v.begin(),v.end());
	int ans=0;
	for(int i : v) {
		if(diff<=K)break;
		diff--;
		ans+=i;
	}
	cout << ans;
	return 0;
}


