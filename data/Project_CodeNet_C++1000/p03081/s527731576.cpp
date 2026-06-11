///A drunk man will find his way home, but a drunk bird may get lost forever...
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define int long long
#define sz(x) (int)x.size()
const int mx = 2000* 100 + 5;
char c[mx], b[mx]; 
string s;
int n, q;
int f(int p){
	for(int i = 0; i < q; i++){
		if(c[i] == s[p]){
			if(b[i] == 'L')
				p--;
			else
				p++;
		}
		if(p < 0)
			return 1;
		if(p >= n)
			return 2;
		
	}

	return 0;
}
int32_t main(){
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin >> n >> q >> s;
	for(int i = 0; i < q; i++)
		cin >> c[i] >> b[i];
	int r = n, l = 0, mid;
	while(r - l > 1){
		mid = (r + l) / 2;

	//	cout << "YO" << endl;
		if(f(mid) == 1)
			l = mid;
		else
			r = mid;
	}
	int r2 = n, l2 = 0;
	while(r2 - l2 > 1){
		mid = (r2 + l2) / 2;
		if(f(mid) == 2)
			r2 = mid;
		else
			l2 = mid;
	}
//	cout << r << " " << l << " " << r2 << " " << l2 << endl;
	cout << r2 - l - 1 << endl;
	return 0;
}
