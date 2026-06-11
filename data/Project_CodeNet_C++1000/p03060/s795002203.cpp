#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> c(n);
	rep(i,n) cin >> v[i];
	rep(i,n) cin >> c[i];
	int x = 0;
	int y = 0;
	int mx = 0;
	rep(is,1<<n){
		x = 0;
		y = 0;
		rep(j,n){
			if(is>>j&1){
			    x += v[j];
			    y += c[j];
			}
		}
		mx = max(mx,x-y);
	}
	cout << mx << endl;
}