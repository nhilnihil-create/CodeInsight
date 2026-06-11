
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999

using namespace std;


int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dxx[8] = { 0,0,1,1,1,-1,-1,-1 };
int dyy[8] = { 1,-1,0,1,-1,0,1,-1 };



int S[20010];

int main() {
	int N;
	cin >> N;
	if (N == 3) {
		cout << 2 << " " << 5 << " " << 63 << endl;
		return 0;
	}
	if (N == 4) {
		cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl;
		return 0;
	}
	else {
		S[0] = 2; S[1] = 3; S[2] = 9; S[3] = 6;
		int cnt =10;
		FOR(i, 4, N) {
			while (cnt % 2 != 0 && cnt % 3 != 0&&cnt%5!=0)cnt++;

			S[i] = cnt;
			cnt++;
		}
		ll sum = 0;
		REP(i, N)sum += S[i];
		FOR(i, 1, 30) {
			if (sum % 30 == i) {
				if (i % 2 == 1) {
					S[2] = 30000 - 60 - i + 9;
				}
				else {
					S[3] = 30000 - 60 - i + 6;
				}
			}
		}
		REP(i, N) {
			cout << S[i] << " ";
		}
	}
}