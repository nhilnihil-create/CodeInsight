#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define Would
#define you
#define please

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int H, W, N;;
	cin >> H >> W >> N;

	pair<int, int> XY[200001];

	rep(i, N) {
		cin >> XY[i].first >> XY[i].second;
	}
	sort(XY, XY + N);
	
	int kotae = H;
	int jama = 0;
	rep(i, N) {
		if (XY[i].second < XY[i].first - jama) {
			kotae = XY[i].first - 1;
			break;
		}
		else if (XY[i].second == XY[i].first - jama) {
			jama++;
		}
	}
	co(kotae);

	Would you please return 0;
}