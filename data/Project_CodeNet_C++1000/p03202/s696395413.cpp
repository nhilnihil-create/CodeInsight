#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	vector<long long>a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	int ok1=1;
	for(int i = 1; i < n; i++) {
		if(a[i]<=a[i-1])ok1=0;
	}
	if(ok1) {
		cout<<1<<endl;
		return 0;
	}
	int s=1,e=n+1;
	while(s+1<e) {
		int m=(s+e)/2;
		int ok=1;
		map<int,int>f;
		int len=0;
		for(int i = 0; i < n; i++) {
			if(a[i]>len) {
				len=a[i];
			} else {
				while(!f.empty() && f.rbegin()->first>=a[i]) {
					f.erase(f.rbegin()->first);
				}
				f[a[i]-1]++;
				int cur=a[i]-1;
				while(f[cur]>=m) {
					f.erase(cur);
					cur--;
					f[cur]++;
					if(cur<0) {
						ok=0;
					}
				}
				if(!ok)break;
				len=a[i];
			}
		}
		if(ok) {
			e=m;
		} else {
			s=m;
		}
	}
	cout<<e<<endl;
	return 0;
}