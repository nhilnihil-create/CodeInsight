#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for(int i=m;i<(int)(n);i++)
typedef long long ll;
typedef pair<ll,ll> pint;
int main(){
    ll n,k;cin>>n>>k;
    vector<ll> a(n);rep(i,n)cin>>a[i];
    vector<ll> s(n+1,0);
    vector<ll> v;
    //priority_queue<ll> que;
    rep(i,n){
        s[i+1]=s[i]+a[i];
    }
    rep(left,n){
        REP(right,left+1,n+1){
            v.push_back(s[right]-s[left]);
        }
    }
    int m=v.size();
    ll ans=0;
    int b=50;
    for(int i=50;0<=i;i--){
        int cnt = 0;
        ll p = pow(2.0,i);
        rep(j,m){
            ll y = v[j];
            //cout<<((ans+p)&y)<<endl;
            if(((ans+p)&y)==(ans+p)){
                cnt++;
                //cout<<cnt<<endl;
            }
        }
        //cout<<ans+p<<endl;
        if(k<=cnt){
            ans+=p;
        }
    }
    cout<<ans<<endl;
    return 0;
}