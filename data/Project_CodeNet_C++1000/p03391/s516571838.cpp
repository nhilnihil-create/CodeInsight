#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#ifdef _debug
#define dout(i) cout << #i << ' ' << i << ' '
#else 
#define dout(i) //
#endif
using ll = long long;
using ull = unsigned long long;
using ul = unsigned;
using db = double;
int dif = 0;
const int maxn = 300000;
ll a[maxn], b[maxn];
int n;
ll res, sum;
int pos;
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i){
		cin >> a[i] >> b[i];
		sum += b[i];
	}
	for(int i = 1;i <= n;++i){
		if(a[i] > b[i])res = max(res, sum-b[i]);
	}
	cout << res << '\n';
}