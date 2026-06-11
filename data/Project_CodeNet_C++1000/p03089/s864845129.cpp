#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<math.h>
#include<bitset>
#include<tuple>
#include<time.h>
#include<list>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n;
vector<int> a;
void solve(){
	cin >> n;
	a.resize(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	bool b[101] = {0};
	vector<int> ans(n);
	for(int i = 0; i < n; i++){
		int cnt = 0, pos = -1;
		for(int j = 0; j < n; j++){
			if(b[j]) continue;
			cnt++;
			if(cnt == a[j]){
				pos = j;
			}
		}
		if(pos == -1){
			cout << -1 << endl;
			return;
		}
		b[pos] = 1;
		ans[n-i-1] = a[pos];
	}
	for(int i = 0; i < n; i++){
		cout << ans[i] << endl;
	}
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}