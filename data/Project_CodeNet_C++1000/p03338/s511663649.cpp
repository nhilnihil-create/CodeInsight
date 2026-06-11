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
int n, maks=-1;
string s;

int main(){
	IOS
	cin >> n >> s;
	for(int i=0;i<n-1;i++){
		int ans=0;
		set<int>s1, s2;
		for(int j=0;j<=i;j++) s1.insert(s[j]);
		for(int j=i+1;j<n;j++) s2.insert(s[j]);
		for(auto x:s1){
			if(s2.count(x)) ans++;
		}
		maks=max(maks, ans);
	}
	cout << maks << '\n';	
}
