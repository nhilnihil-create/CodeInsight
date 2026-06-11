
#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <cmath>   
#include<cctype>
#include<string>
#include<set>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include <deque>
#include <typeinfo>
#include <utility> 
#define all(x) (x).begin(),(x).end()
#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;

int N, A[202020], B[202020];



int check(int d) {
	int msk = 1 << d;
	vector<int>AA(N);
	vector<int>BB[2];
	rep(i, 0, N) {
		AA[i] = A[i]%(2*msk);
		if (B[i]&msk)BB[1].push_back(B[i]%(2*msk));
		else BB[0].push_back(B[i]%(2*msk));
	}
	
	rep(i, 0, 2)sort(all(BB[i]));
 	int cnt = 0;
	rep(i, 0, N) {
		if (AA[i] & msk) {
			int cnt1 = lower_bound(all(BB[1]),3*msk-AA[i]) - BB[1].begin();
			cnt += BB[1].size() - cnt1;
			int cnt2 = lower_bound(all(BB[0]), 2*msk-AA[i]) - BB[0].begin();
			cnt += cnt2;
		}
		else {
			int cnt1 = lower_bound(all(BB[0]), msk - AA[i]) - BB[0].begin();
			cnt += BB[0].size() - cnt1;
			int cnt2 = lower_bound(all(BB[1]), 2 * msk - AA[i]) - BB[1].begin();
			cnt += cnt2;
		}
	}

	if (cnt % 2 != 0)return 1;
	else return 0;
}



int main() {
	cin >> N;
	rep(i, 0, N)cin >> A[i];
	rep(i, 0, N)cin >> B[i];

	int ans = 0;
	rep(d, 0, 29)if (check(d))ans += 1 << d;

	cout << ans << endl;

	return 0;
}