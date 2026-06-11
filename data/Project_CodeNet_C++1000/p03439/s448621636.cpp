///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair <int, int> pii;
#define pb push_back
#define f first
#define s second
#define sz(x) (int)x.size()
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s, t;
	cout << 0 << endl;
	cin >> s;
	if(s == "Vacant")
		return 0;
	int l = 0, r = n, mid;
	while(r - l > 1){
		mid = (r + l) / 2;
		cout << mid << endl;
		cin >> t;
		if(t == "Vacant")
			return 0;
		if(((mid - l) % 2 && s == t) || !((mid - l) % 2) && s != t)
			r = mid;
		else{
			l = mid;
			s = t;
		}
	}
	return 0;
}
