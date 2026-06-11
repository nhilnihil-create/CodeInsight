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
	cin >> s;
	ll ans=0, c=0;
	n = s.length();
	for(i=0;i<n;i++){
		if(s[i] == 'W'){
			c++;
			ans += i-c+1;
		}
	}
	cout << ans;
}
