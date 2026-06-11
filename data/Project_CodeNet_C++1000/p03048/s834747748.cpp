#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {

	int R,G,B,N;
	cin >> R >> G >> B >> N;
	int ans = 0;
	for(int i=0; i<=N/R; i++) {
		for(int j=0; j<=N/G; j++) {
			int temp = N - (i * R + j * G);
			if (temp >= 0 && temp % B == 0) ans++;
		}
	}
	cout << ans << endl;
  return 0;
}
