#include<bits//stdc++.h>
using namespace std;
int n,a[200005];long long ans;
int main(){
	cin >>n;for(int i=1;i<=n;++i)cin >> a[i];a[0]=-1;
	for(int i=1;i<=n+1;++i) {
		if(a[i]==a[i-1]+1) continue;
		else if(a[i]>a[i-1]+1) {cout << -1 <<endl;return 0;}
		else ans+=(long long)a[i-1];
	}cout << ans<<endl;
}