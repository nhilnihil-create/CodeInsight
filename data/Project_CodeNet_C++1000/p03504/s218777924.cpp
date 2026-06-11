#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) v.begin(), v.end()
#define ll long long
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<long long>;
using vvll = vector<vll>;

//snippets:tmp,cl,cvl,cs,co,coy,con,cov

int main(){
    ll n;
    cin >> n;
    ll c;
    cin >> c;
    vll s(n);
    vvll d(c+1,vll(100001,0));
    ll tmax=0;
    rep(i,n){
        ll s;
        cin >> s;
        ll t;
        cin >> t;
        ll ch;
        cin >> ch;
        rep(j,t-s+1){
            d[ch][s+j-1]=1;
        }
        tmax=max(t,tmax);
    }
    ll chmax=0;
    repi(i,1,tmax+1){
        ll num=0;
        repi(j,1,c+1){
            if(d[j][i]==1) num++;
        }
        chmax=max(chmax,num);
    }
    cout<<chmax<<endl;
}