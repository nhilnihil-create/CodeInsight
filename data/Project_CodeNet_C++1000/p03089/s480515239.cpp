#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<ll> vl ;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;

#define rep(i,N) for(int i=0; i < (int)N; i++)
#define all(v) (v).begin(),(v).end()

const int INF = 1001001001;

int main(){
	int n; cin >> n;
	vi b(n); rep(i, n) cin >> b[i];
	vi ans;
	bool ok = true;
	rep(i,n) {
		int pos = -1;
		rep(j, b.size()){
			if (j+1 == b[j]) pos = max(pos, j);
		}
		if(pos != -1){
			ans.push_back(b[pos]);
			b.erase(b.begin()+pos);
		} else ok = false;
	}
	reverse(all(ans));
	if (ok){
	rep(i,n) cout << ans[i] << endl;
	} else {
		cout << -1 <<endl;
	}
}