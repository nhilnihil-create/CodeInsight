#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int a[100010], t[100010], bit[200010];

void bitAdd(int n, int a){
	for(int i=n; i<200010; i += (i&(-i))){
		bit[i] += a;
	}
}

int bitSum(int n){
	int res=0;
	for(int i=n; i>0; i -= (i&(-i))){
		res += bit[i];
	}
	return res;
}

int main() {
	int N;
	cin >> N;
	for(int i=0; i<N; ++i){
		cin >> a[i];
		t[i]=a[i];
	}
	sort(t, t+N);
	int ng=-1, ok=N-1;
	ll total= (ll) N*(N+1)/2;
	while(ng+1<ok){
		int mid=(ng+ok)/2, now=N+1;
		ll sum=0;
		for(int i=0; i<200010; ++i) bit[i]=0;
		for(int i=0; i<N; ++i){
			bitAdd(now, 1);
			if(a[i]<=t[mid]) ++now;
			else --now;
			sum += bitSum(now-1);
		}
		if(sum*2<=total) ng=mid;
		else ok=mid;
	}
	cout << t[ok] << endl;
	return 0;
}