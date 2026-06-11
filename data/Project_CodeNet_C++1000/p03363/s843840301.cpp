#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n;cin>>n;
    ll a[n],b[n];
    rep(i,n)cin>>a[i];
    b[0]=a[0];
    rep(i,n-1)b[i+1]=b[i]+a[i+1];
    
    ll ans = 0;
    ll cc  = 1;
    ll cc0 = 0;
    sort(b, b+n);

    rep(i,n-1){
        if(b[i] == 0)++cc0;

        if(b[i+1] == b[i])++cc;
        if(b[i+1] != b[i]){
            ans += cc*(cc-1)/2;
            cc = 1;
        }
    }

    ans += cc*(cc-1)/2;    

    if(b[n-1]==0)++cc0;
    ans += cc0;

//    rep(i,n)rep(j,i)if(b[i]-b[j]==0)++ans;
//    rep(i,n)if(b[i]==0)++ans;

    cout<<ans<<endl;
	return 0;
}