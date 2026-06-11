#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define IP pair<int,int>
#define enld endl

int main() {
	lint N;
	cin >> N;
	vector<lint>A(N);
	vector<lint>B(N);
	rep(i, N) {
		cin >> A[i] >> B[i];
	}
	lint sumA = 0;
	lint sumB = 0;
	rep(i, N) {
		sumA += A[i];
		sumB += B[i];
	}
	priority_queue<lint>Q;
	rep(i, N) {
		Q.push(A[i] + B[i]);
	}
	lint ans = sumB * (-1);
	rep(i, N) {
		if (i % 2 == 0) {
			ans += Q.top();
			Q.pop();
		}
		else {
			Q.pop();
		}
	}
	cout << ans << enld;
}