#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const ll INF=LONG_LONG_MAX;

int main(){
    int a,b,q;
    cin>>a>>b>>q;
    vector<ll>s(a),t(b);
    rep(i,a)cin>>s[i];
    rep(i,b)cin>>t[i];
    rep(i,q){
        ll x;
        scanf("%lld", &x);
        ll ans=INF;
        ll d1=-1,d2=-1,d3=-1,d4=-1;
        d2=lower_bound(s.begin(),s.end(),x)-s.begin(),d1=d2-1;
        d4=lower_bound(t.begin(),t.end(),x)-t.begin(),d3=d4-1;
        if((0<=d1&&d1<a)&&(0<=d3&&d3<b)){
            ll cnt=max(abs(x-s[d1]),abs(x-t[d3]));
            ans=min(ans,cnt);
        }
        if((0<=d2&&d2<a)&&(0<=d4&&d4<b)){
            ll cnt=max(abs(x-s[d2]),abs(x-t[d4]));
            ans=min(ans,cnt);
        }
        if((0<=d2&&d2<a)&&(0<=d3&&d3<b)){
            ll cnt=min(abs(x-s[d2])*2+abs(x-t[d3]),abs(x-s[d2])+abs(x-t[d3])*2);
            ans=min(ans,cnt);
        }
        if((0<=d1&&d1<a)&&(0<=d4&&d4<b)){
            ll cnt=min(abs(x-s[d1])*2+abs(x-t[d4]),abs(x-s[d1])+abs(x-t[d4])*2);
            ans=min(ans,cnt);
        }
        printf("%lld\n",ans);
    }
}