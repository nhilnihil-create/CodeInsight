#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
const int mx = 200005;
int n, a[mx], l, r = mx;

int main(){
	scanf("%d", &n);
	rep(i,n) scanf("%d", a+i);
	while(l+1 < r){
		int mid = (l+r) / 2, hi = 0;
		bool ok = true;
		map<int, int> mp;
		rep(i,n){
			bool t = hi >= a[i];
			hi = a[i];
			if(t && mid == 1) t = ok = false;
			if(t) while(++mp[hi] >= mid) hi--;
			if(!hi) ok = false;
			mp.erase(mp.upper_bound(hi), mp.end());
		}
		(ok ? r : l) = mid;
	}
	printf("%d\n", r);
}