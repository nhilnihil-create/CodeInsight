#include <bits/stdc++.h>
using namespace std;

using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

int main() {
	int n;
	cin>>n;
	vector<pair<ld,string>> a(n);
	for(int i=0;i<n;i++){
	    cin>>a[i].first>>a[i].second;
	}
	ld ans=0;
    for(int i=0;i<n;i++){
        if(a[i].second=="JPY"){
            ans+=a[i].first;
        }
        if(a[i].second=="BTC"){
            ans+=(380000.0*a[i].first);
        }
    }
    cout<<ans;
	return 0;
}