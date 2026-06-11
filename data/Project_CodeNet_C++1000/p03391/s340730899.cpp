#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long int ll;

const ll INF = 1e9;

int main()
{
	int n;
	cin>>n;
	vector<ll> a(n),b(n);
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i];
	}
	if(a==b){
		cout<<0<<endl;
		return 0;
	}
	ll sum = 0,min_b =INF;
	for(int i = 0; i < n; i++){
		sum+=a[i];
		if(a[i]>b[i])
			min_b = min(min_b,b[i]);
	}
	cout<<sum-min_b<<endl;

	return 0;
}
