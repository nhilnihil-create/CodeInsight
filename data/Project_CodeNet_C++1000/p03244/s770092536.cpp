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
ll n;

struct struk{
		ll cnt, isi;
	};
vector<struk>ganjil(100005), genap(100005);

bool cmp(struk s1, struk s2){
		return s1.cnt>s2.cnt;
	}

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		ll num;
		cin >> num;
		if(i&1){
			ganjil[num].cnt++;
			ganjil[num].isi=num;
		}
		else{
			genap[num].cnt++;
			genap[num].isi=num;
		}
	}
	sort(ganjil.begin(), ganjil.end(), cmp);
	sort(genap.begin(), genap.end(), cmp);
	if(ganjil[0].isi!=genap[0].isi){
		cout << n-(ganjil[0].cnt+genap[0].cnt) << '\n';
		return 0;
	}
	//cout << genap[0].cnt << ' ' << ganjil[0].cnt << '\n';
	ll ans1=n-(ganjil[0].cnt+genap[1].cnt);
	ll ans2=n-(ganjil[1].cnt+genap[0].cnt);
	cout << min(ans1, ans2) << '\n';
}

