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
using namespace std;
typedef  long long int lint;
typedef pair<int, int> IP;
typedef pair<lint, lint> LLP;
typedef pair<char, char>CP;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define llower(v,hoge) *lower_bound(v.begin(), v.end(), hoge)
#define lupper(v,hoge) *upper_bound(v.begin(), v.end(), hoge)
const lint MOD = pow(10, 9) + 7;

int main() {
	lint N;
	cin >> N;
	vector<lint>A(N);
	vector<lint>B(N);
	rep(i, N) {
		cin >> A[i];
	}
	rep(i, N) {
		cin >> B[i];
	}
	lint sumA = 0, sumB = 0;
	rep(i, N) {
		sumA += A[i];
	}
	rep(i, N) {
		sumB += B[i];
	}
	if (sumA < sumB) {
		cout << -1 << endl;
	}
	else {
		lint x = 0, y = 0;
		lint xx = 0;//足りてない量
		rep(i, N) {
			if (A[i] < B[i]) {
				x++;//足りてない数
				xx += B[i] - A[i];
			}
		}
		vector<int>Y;
		rep(i, N) {
			if (A[i] > B[i]) {
				Y.push_back(A[i] - B[i]);
			}
		}
		sort(Y);
		reverse(Y);
		int Z = Y.size();
		vector<lint>SUM(Z);
		SUM[0] = Y[0];
		for (int i = 1; i < Z; i++) {
			SUM[i] = SUM[i - 1] + Y[i];
		}
		rep(i, N) {
			if (SUM[i] >= xx) {
				y = i;
				break;
			}
		}
		if (x == 0)cout << 0 << endl;
		
		else cout << x + y+1 << endl;
	}
}