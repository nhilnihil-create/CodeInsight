#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = 2*1e18;
const int inf = 1e9+7;

using namespace std;

bool v[100005];
stack<ll> v2;
int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
	cin >> N >> K;
	vector<pair<ll,ll>> s(N);
	rep(i,N)cin >> s[i].second >> s[i].first;
	sort(ALL(s),greater<>());
	ll sum = 0,type = 0;
	for(int i=0;i<K;i++){
		sum += s[i].first;
		if(!v[s[i].second]){
			type++;
			v[s[i].second]=1;
		}else{
			v2.push(s[i].first);
		}
	}
	ll ans = sum + type*type;
	for(int i=K;i<N;i++){
		if(v[s[i].second]==1)continue;
		else {
			if(v2.empty())break;
			sum += s[i].first;
			v[s[i].second]=1;
			sum -= v2.top();v2.pop();
			type++;
		}
		ans = max(ans,(sum + type*type));
	}
	cout << ans << endl;
}