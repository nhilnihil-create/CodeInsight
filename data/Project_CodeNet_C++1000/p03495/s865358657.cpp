#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <math.h>
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
typedef long long ll;
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n),c;
    rep(i,0,n) cin >> a[i];
    set<ll> b(a.begin(),a.end());
    if (b.size()<=k) {
        cout << "0" << endl;
        return 0;
    }
    sort(a.begin(),a.end());
    map<ll,ll> m;
    rep(i,0,n) m[a[i]]++;
    int x=0,ans=0;
    vector<ll> cnt(m.size());
    int i=0;
    for(auto p:m) {
        cnt[i]=p.second;
        i++;
    }
    sort(cnt.begin(),cnt.end());
    while (b.size()-k-x) {
        ans+=cnt[x];
        x++;
    }
    cout << ans << endl;
}
