#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
int main(){
    ll n ; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        ll x; cin >> x;
        x--;
        a.at(x)=i;
    }
    ll cnt = 1;
    ll mxm = 0;
    for(int i=1;i<n;i++){
        if(a.at(i)>a.at(i-1)){
            cnt++;
        }else{
            mxm = max(mxm,cnt);
            cnt = 1;
        }
    }
    mxm = max(mxm,cnt);
    cout << n-mxm << endl;
}