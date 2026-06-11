#include <bits/stdc++.h>
using namespace std;
int n;
const int maxn=5e5+100;
int a[maxn],b[maxn];
const int N=3e5+100;
const int dif=1e5+100;
void solve(){
	cin >> n;
	a[dif]++,b[dif]++;
	for (int i=1;i<=n;i++){
		int x,y;cin >> x >> y;
		a[x+dif]++;
		b[y+dif]++;
	}
	for (int i=1;i<N;i++){
		b[i]+=b[i-1]; 
	}
	for (int i=N-1;i>=0;i--){
		a[i]+=a[i+1];
	}
//	for (int i=dif-10;i<=dif+10;i++) cout << a[i] << ' ';
//	cout << endl;
//	for (int i=dif-10;i<=dif+10;i++) cout << b[i] << ' ';
//	cout << endl;
	long long ans=0;
	for (int i=1;i<=N;i++){
		ans+=min((long long)a[i+1],(long long)b[i]);
	}
	cout << ans*2;
}
int main(){
	solve();
	return 0;
}
