#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P; 

int main(){
	int N,M;
	cin >> N >> M;
	vector<P> item(N);
	rep(i,N){ cin >> item[i].first >> item[i].second; }
	sort(item.begin(), item.end());

	ll ans = 0;
	int i=0;
	while(M>0){
		ll num = min(item[i].second, M);
		ans += item[i].first * num;
		M -= num;
		i++;
	}

	cout << ans << endl;
	return 0;
}