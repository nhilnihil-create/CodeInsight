#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<int, int> ii;

#define int ll

const int N = 1e5+100;

int a[N];

signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin >> n;
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	reverse(a, a+n);
	int l=2, r=2;
	for(int i=0 ; i<n ; i++){
		if(r<a[i]){
			cout << "-1\n";
			return 0;
		}
		l += (l%a[i] == 0 ? 0 : a[i] - (l%a[i]));
		if(l>r){
			cout << "-1\n";
			return 0;
		}
		r = (r/a[i])*a[i] + a[i]-1;
	}
	cout << l << " " << r << "\n";
 	return 0;
}














