#include <bits/stdc++.h>
 
using namespace std;

#define esp 1e-9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long int n;
	cin>>n;
	long long int nn=n;
	long long int ans=0;
	while(nn--){
		long long int x;
		cin>>x;
		ans+=x;
	}
	cout<<ans-n;
	return 0;
}