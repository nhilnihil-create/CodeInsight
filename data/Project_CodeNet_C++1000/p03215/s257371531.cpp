#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N,K;
	ll ans = 0;
	cin >> N >> K ;
	vector<ll> a(N),b;
	rep(i,N){
		cin >> a[i];
	}
	for(int i=0;i<N;i++){
		ll sum = a[i];
		b.push_back(sum);
		for(int j=i+1;j<N;j++){
			sum += a[j];
			b.push_back(sum);
		}
	}
	
	bool flag = 0;
	
	for(int m=40;m>=0;m--){
		ll nowbit = (1LL<<m);
		vector<ll> t;
		int cnt = 0;
		for(int i=0;i<b.size();i++){
			if(b[i]&nowbit){
				cnt++;
				t.push_back(b[i]);
			}
		}
		if(cnt>=K){
			ans += nowbit;
			b = t;
			flag = 1;
		}else{
		}
	}
	cout << ans << endl;
}