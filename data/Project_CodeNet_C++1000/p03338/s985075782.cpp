#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int n, m;

int main(){
	int i, j;
	string s;
	cin >> n;
	cin >> s;
	ll ans=0, c=0;
	for(i=1;i<n;i++){
		map<char,bool> a;
		map<char,bool> b;
		c=0;
		for(j=0;j<i;j++){
			a[s[j]] = true;
		}for(j=i;j<n;j++){
			if(a[s[j]] && !b[s[j]])c++;
			b[s[j]] = true;
		}ans = max(c, ans);
	}cout << ans;
}
