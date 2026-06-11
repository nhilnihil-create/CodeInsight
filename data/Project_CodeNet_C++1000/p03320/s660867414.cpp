#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<random>
#include<set>
#include<map>
#include<functional>
using namespace std;
#define int long long
#define inf 1145141919
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int>P;
typedef pair<int, P> PP;
struct edge { int to, cost; };
vector<int>ans0,ans1;
int digit(int n) {
	int res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}
int ipow(int a, int n) {
	int res = 1;
	rep(i, n)res *= a;
	return res;
}
double snk(int a) {
	double A = a, B = digit(a);
	return A / B;
}

signed main() {
	int k; cin >> k;
	rep(i, 9)ans0.push_back(i + 1);
	for(int i=0;i<=15;i++){//末尾の9の数
		int num = ipow(10, i) - 1;
		rep(j, 1000) {
			int n = j*ipow(10, i) + num;
			if(n)ans0.push_back(n);
		}
	}
	sort(ans0.begin(), ans0.end());
	ans0.erase(unique(ans0.begin(), ans0.end()), ans0.end());
	sort(ans0.begin(), ans0.end());
	rep(i, ans0.size()) {
		for (int j = i + 1; j < ans0.size(); j++) {
			if (snk(ans0[i]) > snk(ans0[j]))goto A;
		}
		ans1.push_back(ans0[i]);
	A:;
	}
	rep(i, k)cout << ans1[i] << endl;
	//cout << ans1.size() << endl;
}