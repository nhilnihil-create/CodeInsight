#include<bits/stdc++.h>
#define rep(i, n) for(int i=1; i<int(n); i++)
#define ALL(a) (a).begin(), (a).end()
using namespace std;
typedef long long ll;

bool comp(ll x, ll y){
	ll dx = 0, dy = 0, nx = x, ny = y;
	while(x > 0){
		dx += x % 10;
		x = (x - (x % 10))/10;
	}
	while(y > 0){
		dy += y % 10;
		y = (y - (y % 10))/10;
	}
	if(nx * dy <= ny * dx) return true;
	else return false;
}

int main(){
	int K; cin >> K;
	vector<ll> ans;
	for(int i=1; i<1000; i++){
		ll c = 0, t = 1;
		rep(j, 14){
			ans.push_back(i*t+c);
			c = c * 10 + 9;
			t *= 10;
		}
	}
	sort(ALL(ans));
	int mi[ans.size()];
	mi[ans.size() - 1] = ans.size() - 1;
	for(int i=ans.size()-2; i>=0; i--){
		if(comp(ans[i], ans[mi[i+1]])){
			mi[i] = i;
		}else{
			mi[i] = mi[i+1];
		}
	}
	int now = 0;
	while(K){
		if(now != 0 && ans[now] == ans[now-1]){ now++; continue; }
		if(comp(ans[now], ans[mi[now]])){
			cout << ans[now] << endl;
			K--;
		}
		now++;
	}
	return 0;
}
