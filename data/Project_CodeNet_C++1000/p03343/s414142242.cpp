#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 30005;
const int mod = 998244353;
const int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};

int n, q, k, a[MAXN];

bool trial(int l, int r){
	int cnt = 0;
	for(int i=0; i<n;){
		if(a[i] < l){
			i++;
			continue;
		}
		int e = i;
		while(e < n && a[e] >= l) e++;
		if(e - i >= k){
			int tcnt = 0;
			for(int j=i; j<e; j++){
				if(a[j] <= r) tcnt++;
			}
			cnt += min(tcnt, e - i - k + 1);
		}
		i = e;
	}
	return cnt >= q;
}

vector<int> crd;

int main(){
	cin >> n >> k >> q;
	for(int i=0; i<n; i++){
		cin >> a[i];
		crd.push_back(a[i]);
	}
	sort(crd.begin(), crd.end());
	crd.resize(unique(crd.begin(), crd.end()) - crd.begin());
	int ret = 1e9;
	int e = 0;
	for(int i=0; i<crd.size(); i++){
		while(e < crd.size() && !trial(crd[i], crd[e])) e++;
		if(e < crd.size()) ret = min(ret, crd[e] - crd[i]);
	}
	cout << ret << endl;
}
