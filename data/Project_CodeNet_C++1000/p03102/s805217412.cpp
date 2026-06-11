#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0);cin.tie();cout.tie();
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 9223372036854775807;
const ll mininf = -9223372036854775807;
const ll nax = 0;
int n, m, c;

int main(){
	IOS
	cin >> n >> m >> c;
	ll ans=0;
	int b[m+5], a[m+5];
	for(int i=0;i<m;i++){
		cin >> b[i];
	}
	while(n--){
		for(int i=0;i<m;i++){
			cin >> a[i];
		}
		ll jawab=0;
		for(int i=0;i<m;i++){
			jawab+=a[i]*b[i];
		}
		jawab+=c;
		if(jawab>0){
			ans++;
		}
	}
	cout << ans << '\n';
}