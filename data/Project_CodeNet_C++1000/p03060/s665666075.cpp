#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
	// sengen
	int n;
	// nyuryoku
	cin >> n;
	int c[n],v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=0;i<n;i++) cin >> c[i];
	int s[n];
	for(int i=0;i<n;i++) s[i] = v[i] - c[i];
	sort(s,s+n,greater<int>());
	int ans = 0;
	// keisan
	int i=0;
	while(s[i] > 0 && i < n){
		ans += s[i];
		i++;
	}
	// syutsuryoku
	cout << ans << endl;
}