#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int n,k; cin>>n>>k;
	if ((n+1)/2>=k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
