#include<bits/stdc++.h>
using namespace std;
#define N 2005
#define ll long long
#define debug(a) cout<<#a<<": ";for(auto i:a)cout<<i<<" ";cout<<endl;
#define trace(a) cout<<#a<<": "<<a<< endl;

int b[N];
pair<int,int> a[N];
bool hasToVisit[N],cannotVisit[N];
int n,k,q;
bool check(int st,int en) {
	int i,j;
	memset(cannotVisit,false,sizeof(cannotVisit));
	memset(hasToVisit,false,sizeof(hasToVisit));
	for(i = 1;i < st;i++) {
		cannotVisit[a[i].second] = true;
	}
	for(i = st;i <= en;i++) {
		hasToVisit[a[i].second] = true;
	}
	int cnt = 0;
	set<int> indices;
	set<pair<pair<int,int>, int> > se;
	for(i = 1;i <= n;i++) {
		if(cnt >= q) return true;
		if(cannotVisit[i]) {
			se.clear();
			indices.clear();
			continue;
		}
		if(se.size() < k) {
			se.insert({{b[i],(hasToVisit[i] ? -1 : 0)},i});
			indices.insert(i);
		}
		if(se.size() == k) {
			if(se.begin()->first.second == -1) {
				int id = se.begin()->second;
				indices.erase(id);
				se.erase(se.begin());
				cnt++;
			}
			else {
				int smallestIndex = *indices.begin();
				indices.erase(indices.begin());
				se.erase({{b[smallestIndex],(hasToVisit[smallestIndex] ? -1 : 0)},smallestIndex});
			}
		}
		if(cnt >= q) return true;
	}
	if(cnt >= q) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
	int i,j,l,m,t;
	cin >> n >> k >> q;
	for(int i = 1;i <= n;i++) {
		cin >> a[i].first;
		b[i] = a[i].first;
		a[i].second = i;
	}
	int an = 2e9;
	sort(a+1,a+1+n);
	for(i = 1;i <= n;i++) {
		l = i+q-1;
		int r = n;
		int ans = -1;
		if(l > r) continue;
		if(a[l].first - a[i].first >= an) continue;
		while(l <= r) {
			int mid = (l+r)/2;
			// trace(mid);
			if(check(i,mid)) {
				ans = mid;
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}
		if(ans == -1) break;
		// trace(ans);
		an = min(a[ans].first - a[i].first,an);
	}
	cout << an << endl;
}