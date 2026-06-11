#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
typedef long long LL;

int n;
LL ans, a[N], cnt = N + 5;

int main() {
	cin>>n;
	for(int i = 1; i <= n; i++) 
		cin>>a[i];
	for(int i = n; i; i--) {
		if(a[i] < i - cnt + 1 && cnt <= i) {
			cout<<-1<<endl;
			return 0;
		}
		if(a[i] > i - 1) {
			cout<<-1<<endl;
			return 0;
		}
		if(a[i] == a[i + 1] - 1 || a[i] == 0) continue;
		ans += a[i];
		cnt = min(cnt, i - a[i] + 1);
	}
	cout<<ans<<endl;
	return 0;
}