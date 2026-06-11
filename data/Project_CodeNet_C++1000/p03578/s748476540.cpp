#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const long long inf = 1e9+7;
const long long mod = 1e9+7;

int main(){
    ll n,m;
    map<ll,ll>d;

    cin>>n;
    rep(i,n){
        ll D;
        cin>>D;

        d[D]++;
    }

    cin>>m;
    rep(i,m){
        ll t;
        cin>>t;

        d[t]--;

        if(d[t]<0){
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;

}
