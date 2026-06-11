#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define rep(i,n) for(int i = 0;i<=(int)n;++i)

int main() {
    int r,g,b,n;cin>>r>>g>>b>>n;
    ll ans = 0;
    rep(i,n)rep(j,n){
        int tmp = n  - r*i - g*j;
        if(tmp%b==0 && tmp>=0)++ans;
    }
    cout<<ans<<endl;
	return 0;
}