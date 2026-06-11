#include<bits/stdc++.h>
#define mx 100005

using namespace std;

int n, k, q, a[mx], b[mx], ans = 1000000007;

int main(){
	scanf("%d%d%d", &n, &k, &q);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	copy(a, a+n, b);
	sort(b, b+n);
	for (int i = 0; i < n; i++) {
		int j = 0;
		vector<int> sm;
		while(j < n){
			vector<int> v;
			int l = 0;
			for(; j + l < n && a[j + l] >= b[i]; l++);
			if(l){
				v.insert(v.begin(), a+j, a+j+l);
				sort(v.begin(), v.end());
				if(v.size() >= k){
					sm.insert(sm.end(), v.begin(), v.end() - k + 1);
				}
			}else l = 1;
			j += l;
		}
		if(sm.size() < q) break;
		sort(sm.begin(), sm.end());
		ans = min(ans, sm[q-1] - sm[0]);
	}
	printf("%d\n", ans);
}