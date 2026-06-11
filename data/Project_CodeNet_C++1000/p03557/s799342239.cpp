#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    int n;
    cin>>n;

    vector<int>a(n),b(n),c(n);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());

    ll ans=0;

    rep(i,n){
        ll A=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        ll C=c.end()-upper_bound(c.begin(),c.end(),b[i]);

        ans+=A*C;
    }

    cout<<ans<<endl;

}
