
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

#define rep(i,m,n) for(int i = m;i < n;++i)
using namespace std;
using ll = long long;
using R = double;
const ll inf = 1LL << 50;
const ll MOD = 1e9 + 7;

int N, A[202020], B[202020];
int AA[202020], BB[202020];



int check(int d) {
	int msk = 1 << d;
	vector<int>AA(N);
	vector<int>BB(N);
	rep(i, 0, N) { 
		AA[i] = A[i] % (msk * 2); 
		BB[i] = B[i] % (msk * 2);
	}
	sort(BB.begin(), BB.end());


	int cnt = 0;
	rep(i, 0, N) {
		int s_1 = lower_bound(BB.begin(),BB.end(),2*msk-AA[i])-BB.begin();
		int t_1 = lower_bound(BB.begin(), BB.end(),msk-AA[i])-BB.begin();
		int s_2 = lower_bound(BB.begin(), BB.end(), 4 * msk-AA[i])-BB.begin();
		int t_2 = lower_bound(BB.begin(), BB.end(), 3 * msk-AA[i])-BB.begin();
		cnt += (s_1-t_1)+(s_2-t_2);
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