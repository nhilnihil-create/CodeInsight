#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define f first
#define s second


//var 
int n, v[21], c[21], ans = 0, g;

int main(){
	ios_base::sync_with_stdio(0); 
	cin.tie(0);

	cin >> n;
	for(int i = 1; i<=n; i++)
		cin >> v[i];

	for(int i = 1; i<=n; i++){
		cin >> c[i];
		g = v[i] - c[i];
		if(g > 0) ans += g;
	}

	cout << ans << endl;

	cout.flush();
	return 0;
}