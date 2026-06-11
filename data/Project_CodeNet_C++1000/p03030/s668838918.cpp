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
ll n;
	
struct struk{
		string s;
		ll p, kordinat;
	};
struk masak[105];

bool cmp(struk s1, struk s2){
		if(s1.s!=s2.s){
			return s1.s<s2.s;
		}
		else{
			return s1.p>s2.p;
		}
	}
	
int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> masak[i].s >> masak[i].p;
		masak[i].kordinat=i+1;
	}
	sort(masak, masak+n, cmp);	
	for(int i=0;i<n;i++){
		cout << masak[i].kordinat << '\n';
	}	
}
