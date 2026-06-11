#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, K; cin >> N >> K;
	vector<pair<ll, int>> su(N);
	for (int i = 0; i < N; i++) {
		cin >> su[i].second >> su[i].first;
	}

	sort(su.begin(), su.end(),greater<pair<ll,int>>());
	vector<pair<ll,int>> ans;
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	map<int, int> cnt;
	ll tot = 0, ki = 0;
	for (int i = 0; i < K; i++) {
		ll sc = su[i].first;
		int id = su[i].second;
		if (cnt[id] == 0) {
			ans.push_back(make_pair(sc, id));
			ki++;
		}
		else pq.emplace(sc, id);
		cnt[id]++;
		tot += sc;
	}

	tot += ki * ki;
	ll temp = tot;
	for (int i = K; i < N; i++) {
		ll sc = su[i].first;
		int id = su[i].second;
		if (cnt[id] == 0) {
			cnt[id]++;
			ans.push_back(make_pair(sc, id));
			if (pq.empty())break;
			ll sc2 = pq.top().first;
			int id2 = pq.top().second;
			cnt[id2]--;
			temp -= sc2 + ki * ki;
			ki++;
			temp += sc + ki * ki;
			pq.pop();
			tot = max(tot, temp);
			/*
			cout << "tot=" << tot << " ki=" << ki << " sc=" << sc << endl;
			for (int j = 0; j < ans.size(); j++) {
				cout << ans[j].second << " ";
			}
			cout << endl;
			*/
		}	
	}

	cout << tot << endl;
}