#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cassert>
#define InfL 1000000000
#define InfLL 1000000000000000000LL
#define mod 1000000007
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=(n-1);(i)>=(0);(i)--)
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<db> vd;

int main() {
	int N;
	cin >> N;
	vi A(N);
	rep(i, N)
		cin >> A[i];
	vi Adec;
	int M = 0;
	rep(i, N - 1) {
		if (A[i] >= A[i + 1]) {
			Adec.push_back(A[i + 1]);
			M++;
		}
	}
	if (M == 0) {
		cout << "1" << endl;
		return 0;
	}
	int L = 1;
	int R = InfL * 2;
	while (1) {
		int anstmp = (L + R) / 2;
		if (L == anstmp)
			break;
		map<int, int> Stmp;
		bool can = true;
		rep(i, M) {
			int Atmp = Adec[i];
			for (auto it = Stmp.upper_bound(Atmp); it != Stmp.end();)
				Stmp.erase(it++);
			while (1) {
				Stmp[Atmp]++;
				if (Stmp[Atmp] >= anstmp) {
					Stmp[Atmp] = 0;
					if (Atmp == 1) {
						can = false;
						break;
					}
					Atmp--;
				}
				else
					break;
			}
		}
		if (can)
			R = anstmp;
		else
			L = anstmp;
	}
	int ans = R;
	cout << ans << endl;
	return 0;
}