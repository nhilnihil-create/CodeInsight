#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
using namespace std;
int n;
ll a[200001];
ll fun(ll x){
	ll ret = 0;
	for(int i = 1; i <= n; i++){
	 	ret += abs(a[i]-(x+i));
 	}
 	return ret;
}
int main(){
	cin >> n;
	vector<ll> vec;
	for(int i = 1; i <= n; i++){
	 	cin >> a[i]; vec.pb(a[i]-i);
	}
	sort(vec.begin(),vec.end());
	ll res;
	if(vec.size()%2 == 0){
	 	res = fun((vec[vec.size()/2-1]+vec[vec.size()/2+1-1])/2);
	}
	else res = fun(vec[vec.size()/2+1-1]);
	cout << res << endl;
	return 0;
}                  
