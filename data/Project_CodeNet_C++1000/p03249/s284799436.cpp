#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>

#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;

const int MAX_N = 100001;
int n;
ll input[MAX_N];
int sz[MAX_N];
int par[MAX_N];
ll sum[MAX_N];

vector<pair<ll, int>> v;

int main(void) {
	scanf("%d", &n);
	ll temp;
	for(int i=1; i<=n; i++) {
		scanf("%lld", &temp);
		v.push_back(make_pair(temp, i));
	}

	sort(all(v));
	for(int i=0; i<n; i++) input[i] = v[i].first;
	for(int i=0; i<n; i++) sz[i] = 1;

	for(int i=n-1; i>0; i--) {
		ll temp = input[i]+sz[i]+sz[i]-n;
		int idx = lower_bound(input, input+n, temp)-input;
		if(input[idx] != temp) {
			printf("-1");
			return 0;
		}

		par[i] = idx;
		sz[idx]+=sz[i];
		sum[idx]+=sum[i]+sz[i];
	}

	if(sum[0] != input[0]) {
		printf("-1");
		return 0;
	}

	for(int i=1; i<n; i++) {
		printf("%d %d\n", v[par[i]].second, v[i].second);
	}
}
