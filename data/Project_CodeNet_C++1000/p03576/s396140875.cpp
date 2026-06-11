#include <bits/stdc++.h>

using namespace std;

int main() {
	int n,k; cin >> n >> k;
	vector<long long> x(n),y(n);
	vector<pair<int,int> >xy(n);
	for(int i=0;i<n;++i) {
		cin >> x[i] >> y[i];
		xy[i]=make_pair(x[i],y[i]);
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	long long ans=9e18;
	for(int x1=0;x1<n;++x1) {
		for(int x2=x1+1;x2<n;++x2) {
			for(int y1=0;y1<n;++y1) {
				for(int y2=y1+1;y2<n;++y2) {
					int cnt=0;
					for(int i=0;i<n;++i) {
						if(x[x1]<=xy[i].first&&xy[i].first<=x[x2]&&
						   y[y1]<=xy[i].second&&xy[i].second<=y[y2]) ++cnt;
					}
					if(cnt>=k) ans=min(ans,(x[x2]-x[x1])*(y[y2]-y[y1]));
				}
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}
