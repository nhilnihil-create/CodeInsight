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
const ll nax = 0;
string s;
ll k;

int main(){
	IOS
	cin >> s >> k;
	ll cnt=0, sais=s.size();
	string ini;
	for(int i=0;i<sais;i++){
		if(s[i]=='1'){
			cnt++;
		}
		else{
			ini=s[i];
			break;
		}
	}
	if(cnt>=k){
		cout << 1 << '\n';
		return 0;
	}
	cout << ini << '\n';
}	

