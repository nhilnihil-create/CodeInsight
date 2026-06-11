#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2E5+2;
 
int n;
vector<pair<long long, int> > a(MAXN);
vector<bool> b(MAXN, 0);
vector<pair<int,int> > v;
 
long long pairing(long long X){
	int l = 0, r = 60, msb = 60;
	while(l<=r){
		int mid = (l+r)>>1;
		long long val = (1LL << mid);
		if(val > X) msb = mid, r = mid-1;
		else l = mid+1;
	}
	return (1LL<<msb) - X;
}
 
int main() {
	// your code goes here
	cin >> n;
	for(int i=1; i<= n; ++i){
		cin >> a[i].first; a[i].second = i;
	}
	sort(a.begin()+1, a.begin()+n+1);
	for(int i=n; i>= 1;--i){
		if(b[i]) continue;
		long long X = pairing(a[i].first);
		int l = 1, r = i-1, j = -1;
		while(l<=r){
			int mid = (l+r)>>1;
			
			if(a[mid].first < X) l = mid+1;
			else if(a[mid].first > X) r =mid-1;
			else if(b[mid]) l = mid+1;
			else j = mid, r = mid-1;
		}
		if(j!= -1){
			v.push_back({a[i].second, a[j].second});
			b[j] = 1;
		}
	}
	cout << v.size() << "\n";
	return 0;
}