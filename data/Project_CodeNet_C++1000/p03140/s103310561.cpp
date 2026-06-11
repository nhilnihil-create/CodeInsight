#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n;
	cin >> n;
	string a,b,c;
	cin >> a >> b >> c;
	vector<int> x(n);
	rep(i,n){
		int cnt=1;
		if(a[i]==b[i]) cnt++;
		if(b[i]==c[i]) cnt++;
		if(a[i]==c[i]) cnt++;
		if(a[i]==b[i]&&a[i]==c[i])
			cnt--;
		x[i]=cnt;
	}
	int sum=0;
	rep(i,n) sum+=x[i];
	cout << n*3-sum << endl;
	return 0;
}

