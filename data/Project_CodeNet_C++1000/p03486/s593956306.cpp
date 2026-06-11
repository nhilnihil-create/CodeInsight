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
string s, t;
	
int main(){
	IOS
	cin >> s >> t;
	bool sama=1;
	int c=s.length(), d=t.length();
	for(int i=0;i<min(c, d);i++){
		if(s[i]!=t[i]){
			sama=0;
			break;
		}
	}
	if(sama){
		if(s.length()<t.length()){
			cout << "Yes" << '\n';
		}
		else{
			cout << "No" << '\n';
		}
		return 0;
	}
	sort(s.begin(), s.end());
	sort(t.rbegin(), t.rend());
	if(s[0]<t[0]){
		cout << "Yes" << '\n';
	}
	else{
		cout << "No" << '\n';
	}
}
