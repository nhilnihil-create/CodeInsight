#include<bits/stdc++.h>

using namespace std;

#define int long long


#define MAX 2000*2000 + 5



signed main(){
	int n; cin>>n;
	vector<int> a(n);
	int sum = 0;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		sum += a[i];
	}

	bitset<MAX> b;

	for(int i = 0; i < n; i++){
		b |= (b<<(a[i]));
		b.set(a[i]);
	}
	// for(int i = 0; i < 102; i++){
	// 	cout<<b[i];
	// }
	// cout<<endl;
	double half = sum/2.00 + 0.1;
	int ans = -100;
	for(int i = 0; i < MAX; i++){
		if(b[i] == 1){
			if(abs(half - i) < abs(half - ans)){
				ans = i;
			}
			
		}
	}
	cout<<ans<<endl;
}