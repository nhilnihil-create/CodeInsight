#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	vector<int>a(n),b(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n; i++) {
		cin>>b[i];
	}
	long long sum_a=0,sum_b=0;
	for(int i=0; i<n; i++) {
		sum_a+=a[i];
	}
	for(int i=0; i<n; i++) {
		sum_b+=b[i];
	}
	long long cnt=sum_b-sum_a,cnt_a=0,cnt_b=0;
	for(int i=0; i<n; i++) {
		int x=b[i]-a[i];
		if(x<0) {
			cnt_a+=abs(x);
		} else {
			cnt_b+=(x+1)/2;
		}
	}
	if(cnt>=cnt_a&&cnt>=cnt_b) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
	return 0;
}

