#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n,h,w;cin>>n>>h>>w;
    int ans=0;
    rep(i,n){
        int a,b;cin>>a>>b;
        if(a>=h && b>=w)++ans;
//        else if(a<=w && b<=h)++ans;
    }
    cout<<ans<<endl;
	return 0;
}