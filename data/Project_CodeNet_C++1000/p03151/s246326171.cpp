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
    vll plus;
    ll mi=0;
    ll count=0;
    vll a(n);
    rep(i, n) cin >> a[i];
    vll b(n);
    rep(i, n) cin >> b[i];
    rep(i,n){
        if(a[i]>b[i]) plus.push_back(a[i]-b[i]);
        else if(b[i]>a[i]){
            mi+=b[i]-a[i];
            count++;
        }
    }
    sort(all(plus));
    reverse(all(plus));
    if(mi==0){
        cout<<0<<endl;
        return 0;
    }
    rep(i,plus.size()){
        mi-=plus[i];
        count++;
        if(mi<=0){
            cout<<count<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}