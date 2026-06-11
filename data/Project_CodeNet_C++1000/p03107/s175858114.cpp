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
string a;
unordered_map<int, int>v;
	
int main(){
	IOS
	cin >> a;
	int b=a.length();
	for(int i=0;i<b;i++){
		if(a[i]=='1'){
			v[1]++;
		}
		else v[0]++;
	}
	cout << 2*min(v[0], v[1]) << '\n';
}
