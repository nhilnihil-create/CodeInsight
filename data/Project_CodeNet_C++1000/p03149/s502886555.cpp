#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

int a[10];
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int n;
	n = 4;
	int x;
	rep(i,n){
		cin >> x;
		a[x]++;
	}
	if(a[1] && a[9] && a[7] && a[4])cout << "YES" << endl;
	else cout << "NO" << endl;
}