#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;

int main() {
    int a[4];
    rep(i,4)cin>>a[i];
    sort(a,a+4);
    int ans= 1000 * a[0] + 100 * a[1] + 10 * a[2] + a[3];
    if(ans==1479)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

//    cout<<ans<<endl;
	return 0;
}