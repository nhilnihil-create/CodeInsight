#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n,m;
	cin >> n >> m;
	int two = 1;
	rep(i,m){
		two *= 2;
	}
	int ans = (m*1900+(n-m)*100)*two;
	cout << ans << endl;
    return 0;
}

