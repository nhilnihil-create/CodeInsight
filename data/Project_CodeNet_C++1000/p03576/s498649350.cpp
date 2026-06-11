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
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=9e18;
const double PI=3.14159265359;

int main() {
    int N, K;
    cin>>N>>K;
    ll x[N], y[N];
    map<ll, int> xmap;
    map<ll, int> ymap;
    vector<ll> xarr, yarr;
    for(int i=0;i<N;++i){
        cin>>x[i]>>y[i];
        if(xmap[x[i]]==0) xarr.push_back(x[i]);
        if(ymap[y[i]]==0) yarr.push_back(y[i]);
        xmap[x[i]]++;
        ymap[y[i]]++;
    }
    sort(xarr.begin(), xarr.end());
    sort(yarr.begin(), yarr.end());
    ll ans = big;
    int tmp;
    ll x1, y1, x2, y2;
    for(int i=0;i<xarr.size();++i){
        for(int j=i+1;j<xarr.size();++j){
            for(int k=0;k<yarr.size();++k){
                for(int l=k+1;l<yarr.size();++l){
                    x1 = xarr[i];
                    x2 = xarr[j];
                    y1 = yarr[k];
                    y2 = yarr[l];
                    tmp = 0;
                    for(int m=0;m<N;++m){
                        if((x1<=x[m]) & (x[m]<=x2) & (y1<=y[m]) & (y[m]<=y2)) tmp++;
                    }
                    if((tmp>=K) & (ans>(x2-x1)*(y2-y1))){
                        ans = (x2-x1)*(y2-y1);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
