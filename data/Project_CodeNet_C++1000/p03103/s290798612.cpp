#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
ll n, m, ans=0, banyak=0;
	
struct struk{
		ll a, b;
	};	
struk minum[nax];

bool cmp(struk s1, struk s2){
		return s1.a<s2.a;
	}
	
int main(){
	IOS
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> minum[i].a >> minum[i].b;
	}
	sort(minum, minum+n, cmp);
	for(int i=0;i<n;i++){
		while(minum[i].b>0&&banyak<m){
			ans+=minum[i].a;
			banyak++;
			minum[i].b--;
		}
	}
	cout << ans << '\n';
}
