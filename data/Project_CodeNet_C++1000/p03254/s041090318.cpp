#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
	int n,x;
	cin >> n >> x;
	vector <int> v(n);
	rep(i,n) cin >> v[i];
	sort(v.begin(), v.end());
	int ans=0;
	rep(i,n){
		if(i==n-1){
			if(x==v[i]){
				ans++;
			}else{
				break;
			}
		}else if(x>=v[i]){
			x-=v[i];
			ans++;
		}else{
			cout << ans << endl;
			return 0;
			break;
		}
	}
	cout << ans << endl;
}
