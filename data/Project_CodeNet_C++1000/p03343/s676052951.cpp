#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
typedef long double ld;
using namespace std;

int a[2020], num[2020], flake[2020];
pair<int, int> p[2020];

int main() {
	int N, K, Q;
	cin >> N >> K >> Q;
	for(int i=0; i<N; ++i){
		cin >> a[i];
		p[i]=make_pair(a[i], i);
		num[i]=1;
	}
	sort(p, p+N);
	int ans=p[Q-1].first-p[0].first;
	for(int i=0; i<N; ++i){
		num[p[i].second]=0;
		int sum=0, now=1;
		for(int j=0; j<N; ++j){
			if(num[j]==0){
				sum += max(0, flake[now]-K+1);
				++now;
			}else{
				num[j]=now;
				++flake[now];
			}
		}
		sum += max(0, flake[now]-K+1);
		if(sum<Q) break;
		int d=i+1, cnt=0, mn, mx;
		while(cnt<Q){
			if(flake[num[p[d].second]]>=K){
				++cnt;
				--flake[num[p[d].second]];
				if(cnt==1) mn=p[d].first;
				if(cnt==Q) mx=p[d].first;
			}
			++d;
		}
		ans=min(ans, mx-mn);
		for(int j=0; j<=now; ++j) flake[j]=0;
	}
	cout << ans << endl;
	return 0;
}