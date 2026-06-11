#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main() {
    int n,k;cin>>n>>k;
    int ans = 1;
    ans+=(n-k)/(k-1);
    if((n-k)%(k-1)!=0)ans++;

    cout<<ans<<endl;
	return 0;
}