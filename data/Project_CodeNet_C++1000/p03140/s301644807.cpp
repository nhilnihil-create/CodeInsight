#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n; cin >> n;
	string a,b,c;
	cin >> a >> b >> c;
	int ans = 0;
	rep(j,n){
		int count = 0;
		if(a[j] == b[j] && b[j] == c[j]){
			count = 0;
		}else if(a[j] == b[j] || b[j] == c[j] || a[j] == c[j]){
			count = 1;
		}else{
			count = 2;
		}
		ans += count;
	}
	cout << ans << endl;
	
    return 0;
}

