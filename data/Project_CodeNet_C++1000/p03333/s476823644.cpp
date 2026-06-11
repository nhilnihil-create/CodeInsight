#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e5+100;
vector < int > a,b;
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	cin >> n;
	for (int i=0;i<n;i++){
		int u,v;cin >> u >> v;
		a.push_back(u),b.push_back(v);
	}
	a.push_back(0),b.push_back(0);
//	for (int i=0;i<n+1;i++) cout << a[i] << ' ';
//	cout << endl;
//	cout << (*a.begin()) << ' ' << (*a.end()) << endl;
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end());
//	for (int i=0;i<n+1;i++) cout << a[i] << ' ';
//	cout << endl;
	long long ans=0;
	for (int i=0;i<=n;i++){
		if (a[i]>b[i]){
			ans+=(a[i]-b[i])*2;
		}
	}
	cout << ans;
}
int main(){
	solve();
	return 0;
}
