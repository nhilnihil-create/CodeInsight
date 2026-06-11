#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	int n;cin>>n;
	vector<int> b(n);
	vector<int> ans(n);
	for(int i = 0; i < n; i++) {
		cin>>b[i];b[i]--;
	}
	for(int i = 0; i < n; i++) {
		int x = -1;
		for(int j = 0; j < b.size(); j++) {
			if (b[b.size() - j - 1] == b.size() - j - 1){
				x = b.size() - 1 - j;
				b.erase(b.begin() + b.size() - j - 1);
				break;
			}
		}
		if (x == -1){
			cout << x << endl;
			return 0;
		}
		ans[n - i - 1] = x;
	}
	for(int i = 0; i < n; i++) {
		cout << ans[i] + 1 << endl;
	}



	return 0;
}