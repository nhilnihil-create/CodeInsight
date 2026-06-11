#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

ll findm(vll &c){
    ll min=1000000;
    ll key=0;
    rep(i,c.size()){
        if(min>c[i]){
            min=c[i];
            key=i;
        }
    }
    return key;
}


int main(){
    ll n;
    cin >> n;
    vvll d(n);
    vll co(n,0);
    rep(i,n-1){
        ll a;
        cin >> a;
        ll b;
        cin >> b;
        d[a-1].push_back(b-1);
        d[b-1].push_back(a-1);
        co[a-1]++;
        co[b-1]++;
    }
    vll c(n);
    rep(i, n) cin >> c[i];
    sort(all(c));
    vll a(n);
    ll ans=0;
    rep(i,n){
        ll k=findm(co);
        a[k]=c[i];
        rep(j,d[k].size()){
            if(co[d[k][j]]==100000) ans+=a[d[k][j]];
            else co[d[k][j]]--;
        }
        co[k]=100000;
    }
    cout << ans << endl;
    rep(i,n-1) cout<<a[i]<<" ";
    cout<<a[n-1]<<endl;
}