#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long int ll;

int main(){
	int n; cin >> n;
	vector<ll> a(n),b(n);
	ll mi=1e9;
	ll sum=0;
	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		if(a[i]>b[i])mi=min(mi,b[i]);
		sum+=a[i];
	}
	if(a==b){
		cout << 0 << endl;
	}
	else{
		cout << sum-mi << endl;
	}
	return 0;
}