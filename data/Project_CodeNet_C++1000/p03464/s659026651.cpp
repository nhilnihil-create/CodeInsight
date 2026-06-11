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
    ll k;
    cin >> k;
    vll a(k);
    rep(i, k) cin >> a[i];
    reverse(all(a));
    ll min=2;
    ll max=2;
    rep(i,k){
        if(a[i]>max){
            cout << -1 << endl;
            return 0;
        }else if(min<a[i]) min=a[i];
        min=(min+a[i]-1)/a[i]*a[i];
        max=max-max%a[i]+a[i]-1;
    }
    if(min>max){
        cout << -1 << endl;
        return 0;
    }
    cout << min<<" "<<max << endl;
}