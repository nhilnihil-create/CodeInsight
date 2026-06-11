#include<bits/stdc++.h>
using namespace std;
#define M 1000005
#define ll long long

ll n, p, ans = 1;
bool dd[M];
vector<ll> v;

int main(){
	cin >> n >> p;
	if (n == 1){
		cout << p;
		return 0;
	}
	for (int i = 2; i < M; i++){
		if (!dd[i]){
			v.push_back(i);
			for (int j = 2*i; j < M; j += i) dd[j] = true;
		}
	}
	for (int i = 0; i < v.size(); i++){
		ll cnt = 0;
		while (p > 0 && p%v[i] == 0) cnt++, p /= v[i];
		if (cnt > 0) ans *= pow(v[i], cnt/n);
	}
	cout << ans;
	return 0;
}
