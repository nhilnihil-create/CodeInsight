#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
ll n, m;

int main(){
	IOS
	cin >> n >> m;
	if(n==1&&m==1){
		cout << 1 << '\n';
	}
	else if(n==1 && m!=1){
		cout << m-2 << '\n';
	}
	else if(m==1 && n!=1){
		cout << n-2 << '\n';
 	}
	else{
		cout << (m-2)*(n-2) << '\n';
	}
}
	
