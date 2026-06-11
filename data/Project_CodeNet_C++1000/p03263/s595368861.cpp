#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll h,w;
	cin>>h>>w;
	ll a[502][502];
	for(ll i=0;i<h;i++){
		for(ll j=0;j<w;j++){
			cin>>a[i][j];
		}
	}
	vector<ll>sy,sx,ey,ex;
	for(ll i=0;i<h-1;i++){
		for(ll j=0;j<w;j++){
			if(a[i][j]%2!=0){
				a[i+1][j]++;
				sy.push_back(i);
				sx.push_back(j);
				ey.push_back(i+1);
				ex.push_back(j);
			}
		}
	}
	for(ll j=0;j<w-1;j++){
		if(a[h-1][j]%2!=0){
			a[h-1][j+1]++;
			sy.push_back(h-1);
			sx.push_back(j);
			ey.push_back(h-1);
			ex.push_back(j+1);
		}
	}
	cout << sy.size()<<endl;
	for(ll i=0;i<sy.size();i++){
		cout << sy[i]+1<<" "<<sx[i]+1<<" "<<ey[i]+1<<" "<<ex[i]+1<<endl;
	}
	// your code goes here
	return 0;
}