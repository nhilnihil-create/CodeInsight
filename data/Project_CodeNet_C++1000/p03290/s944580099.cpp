#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

//read_code(drken)
int main() {
    int d;cin>>d;
    ll g;cin>>g;
    vector<ll>p,c;
    p.resize(d); c.resize(d);
    rep(i,d)cin>>p[i]>>c[i];

    ll ans = 1e+15;
    rep(bit,1<<d){
        ll sum=0;
        ll cc =0;
        rep(i,d)if(bit & (1<<i)){
            sum+=c[i]+p[i]*100*(i+1);
            cc +=p[i];
        }
            if(sum>=g)ans = min(ans,cc);
            else{
                for(int i = d-1;i>=0;--i){
                    if(bit & (1<<i))continue;
                    rep(j,p[i]){
                        if(sum>=g)break;
                        sum+=100*(i+1);
                        ++cc;
                    }
                }
            }
            ans=min(ans,cc);
        }
    cout<<ans<<endl;
	return 0;
}