#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    ll h,w,d;
    cin >>h>>w>>d;
    vector<P>p(h*w);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            ll a;cin >>a;
            a--;
            p[a]=make_pair(i,j);
        }
    }
    vector<ll>a(h*w,0);
    for (int i = 0; i < h * w; ++i) {
        if(i<d)a[i]=0;
        else {
            a[i]=a[i-d]+abs(p[i].first-p[i-d].first)+abs(p[i].second-p[i-d].second);
        }
    }
    ll q;cin >>q;
    for (int i = 0; i < q; ++i) {
        ll l,r;cin >>l>>r;
        l--,r--;
        cout <<a[r]-a[l]<<endl;
    }
    return 0;
}
