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

	int N;
	cin >> N;
	vector<int> C(N),S(N),F(N);
	rep(i,N) cin >> C[i] >> S[i] >> F[i];
	rep(i,N) {
		ll ans = 0;
		ll ct = 0;
		for(int j=i; j<N-1; j++) {
			//cout << ct << " ";
			if(ct <= S[j]) {
				ct = S[j];
			}
			else {
				if((ct-S[j])%F[j] != 0) {
					ct += F[j] - ct % F[j];
				}
			}
			ct += C[j];
		}
		//cout << endl;
		cout << ct << endl;
	}
  return 0;
}
