#include <bits/stdc++.h>

#define REP(i, s,  n) for(int i = s;i < (n);i++)
#define VSORT(v) sort(v.begin(), v.end());
#define int64 long long
#define pb(a) push_back(a)
#define REP64(i, s,  n) for(int64 i = s;i < (n);i++)
#define INF 999999999
#define MOD 1000000007
using namespace std;

typedef pair<int, int> P;
typedef pair<int, P> PP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//---------------------------------------------------------------
//---------------------------------------------------------------

int N;
int64 a[50];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int64 m = 0, mi = -1;
	REP(i, 0, N) {
		cin >> a[i];
		if(m < abs(a[i])) {
			m = abs(a[i]);
			mi = i;
		}
	}
	if(mi == -1) {
		cout << 0 << endl;
	} else {
		cout << (N*2 - 2) << endl;
		REP(i, 0, N)
			if(i != mi)					cout << (mi+1) << " " << (i+1) << endl;
		if(a[mi] > 0) {
			REP(i, 0, N-1)				cout << (i+1) << " " << (i+2) << endl;
		} else {
			for(int i=N-1; i > 0; i--)	cout << (i+1) << " " << (i) << endl;
		}
	}
	
	return 0;
}
