#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=3.14159265359;

int main() {
    ll D, G;
    cin>>D>>G;
    ll p[D], c[D];
    for(ll i=0;i<D;++i){
        cin>>p[i]>>c[i];
    }
    ll ans = big;
    ll tmpans;
    ll tmpscore;
    for(ll bit=0;bit<(1<<D);++bit){
        tmpans = 0;
        tmpscore = 0;
        for(ll i=0;i<D;++i){
            if((bit&(1<<i))!=0){
                tmpans += p[i];
                tmpscore += p[i] * 100 * (i+1);
                tmpscore += c[i];
            }
        }
        if(tmpscore<G){
            for(ll j=D-1;j>=0;--j){
                if((bit&(1<<j))==0){
                    if(tmpscore + p[j] * 100 * (j+1) >= G){
                        if((G-tmpscore)%(100*(j+1))==0){
                            tmpans += (G-tmpscore)/(100*(j+1));
                            tmpscore = G;
                        }
                        else{
                            tmpans += (G-tmpscore)/(100*(j+1)) + 1;
                            tmpscore = G;
                        }
                    }
                    break;
                }
            }
        }
        //cout<<bit<<endl;
        //cout<<tmpans<<" "<<tmpscore<<endl;
        if((tmpans<ans)&(tmpscore>=G))ans = tmpans;
    }
    cout<<ans<<endl;
}

