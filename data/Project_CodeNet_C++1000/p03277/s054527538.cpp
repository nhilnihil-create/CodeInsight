#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;

int N;
vector<int> v;
vector<int> arr;
vector<int> num;
multiset<int> mst;
ll M;

struct SEG{
	SEG(int l, int r, int sum) : l(l), r(r), sum(sum) {}
	int l, r;
	int sum;
};
vector<SEG> seg;

void update(int idx, int s, int e, int x, int y){
	seg[idx].sum+=y;
	if(s==e)	return;
	if(x<=(s+e)/2){
		if(seg[idx].l==-1){
			seg[idx].l = seg.size(); seg.push_back({-1, -1, 0});
		}
		update(seg[idx].l, s, (s+e)/2, x, y);
	}else{
		if(seg[idx].r==-1){
			seg[idx].r = seg.size(); seg.push_back({-1, -1, 0});
		}
		update(seg[idx].r, (s+e)/2+1, e, x, y);
	}
}

int sum(int idx, int s, int e, int x, int y){
	if(idx==-1)	return 0;
	if(x<=s && e<=y)	return seg[idx].sum;
	if(s>y || e<x)	return 0;
	return sum(seg[idx].l, s, (s+e)/2, x, y)+sum(seg[idx].r, (s+e)/2+1, e, x, y);
}



int main(){
	scanf("%d", &N);
	seg.push_back({-1, -1, 0});
	M = ((ll)N * (ll)(N+1))/2;
	for(int i=0; i<N; i++){
		int x; scanf("%d", &x); arr.push_back(x); v.push_back(x); num.push_back(x);
	}sort(num.begin(), num.end());
	int s = 0, e = N-1, m;
	ll cnt;
	while(s<e){
		m = (s+e)/2;
		cnt = 0;
		int now = num[m];
		//cout<<now<<endl;
		for(int i=0; i<v.size(); i++){
			if(arr[i]<=now)	v[i] = 1;
			else v[i] = -1;
		}
		int t = 0;
		update(0, 0, N*2, N, 1);
		for(int i=0; i<v.size(); i++){
			t += v[i];
			cnt += (ll)sum(0, 0, N*2, 0, N+t-1);
			//cout<<t<<' '<<i<<' '<<sum(0, 0, N*2, 0, N+t-1)<<endl;
			update(0, 0, N*2, N+t, 1);
		}
		t = 0;
		update(0, 0, N*2, N, -1);
		for(int i=0; i<v.size(); i++){
			t+=v[i];
			update(0, 0, N*2, N+t, -1);
		}
		if(cnt>=M/2+1){
			e = m;
		}else{
			s = m+1;
		}
	}
	printf("%d", num[s]);

}