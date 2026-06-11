#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    ll a_sum=0,b_sum=0;
    rep(i,n){
        cin >> a[i];
        a_sum += a[i];
    }
    rep(i,n){
        cin >> b[i];
        b_sum += b[i];
    }
    if(a_sum<b_sum){
        cout << -1 << endl;
        return 0;
    }

    vector<ll> c(n);
    rep(i,n){
        c[i] = a[i] - b[i];
    }

    sort(c.begin(),c.end());
    ll need=0;
    int cnt=0;
    int i=0;
    while(c[i]<0){
        need -= c[i];
        cnt++;
        i++;
    }
    i = n-1;
    while(need>0){
        need -= c[i];
        cnt++;
        i--;
    }
    cout << cnt << endl;
}