#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main() {
    int n;cin>>n;
    int a[n];
    rep(i,n)cin>>a[i];
    sort(a,a+n);
    int ans = a[n-1]-a[0];

    cout<<ans<<endl;
	return 0;
}