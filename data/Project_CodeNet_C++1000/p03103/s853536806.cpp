#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long k;
	cin >> k;
	multimap<long long, long long> map1;
	for(long long i=0;i<n;i++){
		long long a;
		cin>>a;
		long long b;
		cin>>b;
		map1.insert(pair<long long, long long>(a, b));
	}
	long long ans=0;
	for (auto& x: map1) {
		if(x.second < k){
			ans+=(x.first)*(x.second);
			k-=x.second;
		}else{
			ans+=(x.first)*k;
			break;
		}
	}

	cout<<ans;
	return 0;
}
