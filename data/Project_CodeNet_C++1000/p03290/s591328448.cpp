#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   ll d,g;cin >>d>>g;
   ll ans=INF;
   vector<ll>p(d);
   vector<ll>c(d);
   g/=100;
    for (int i = 0; i < d; ++i) {
        cin >>p[i]>>c[i];
        c[i]/=100;
    }
    ll copy=g;
    for (int i = 0; i < (1 << d); ++i) {
//        vector<ll>cnt(10,0);
        vector<bool>ch(d,true);
        ll now=0;
        ll g=copy;
        for (int j = 0; j < d; ++j) {
            if(i&(1<<j)){
                ch[j]=false;
                now+=p[j];
                g-=(j+1)*p[j];
                g-=c[j];
//                cnt[j]+=p[j];
            }
        }
        for (int j = d-1; j >=0; --j) {
            if(g<=0){
                ans=min(ans,now);
            }
            else if(ch[j]) {
                if (g < (j + 1) * p[j]) {
                    now += (g - 1) /(j+1) + 1;
                    g -= ((g - 1) /(j+1)+ 1) * (j + 1);
                }
            }
        }
        if(g<=0){
            ans=min(ans,now);
        }
    }
    cout <<ans <<endl;
   return 0;
}