#include <bits/stdc++.h>

int n;
int a[200003];
int main()
{
	scanf("%d",&n);
	for(int i = 0;i < n;++i) scanf("%d",&a[i]);
	if(n == 1) {
		printf("1\n");
		return 0;
	}
	int l = 0, r = n;
	while(r-l>1) {
		int mid = (l+r)>>1;
		std::stack<std::pair<int,int> > s;
		bool ok = true;
		for(int i = 0;i < n;++i) {
			while(!s.empty() && s.top().first >= a[i]) s.pop();
			if(i == 0 || a[i] > a[i-1]) continue;
			int k = a[i]-1;
			while(!s.empty() && s.top().first == k && s.top().second == mid-1) {
				s.pop();
				--k;
			}
			if(k == -1) {
				ok = false;
				break;
			} else if(!s.empty() && s.top().first == k) {
				s.top().second++;
			} else {
				if(mid == 1) {
					ok = false;
					break;
				}
				s.push(std::make_pair(k,1));
			}
		}
		if(ok) {
			r = mid;
		} else {
			l = mid;
		}
	}
	printf("%d\n", r);
}
