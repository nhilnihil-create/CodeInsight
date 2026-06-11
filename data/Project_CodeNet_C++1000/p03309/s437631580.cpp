#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll=long long;
using vi = vector<int>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=(int)1e9+7;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n){
        int b;
        cin >> b;
        a[i] = b - (i+1);
    }
    sort(a.begin(),a.end());
    ll ans;
    if(n%2==0){
        int b,c;
        b = a[n/2-1];
        c = a[n/2];
        ll b_sum=0,c_sum=0;
        rep(i,n){
            b_sum += abs(a[i]-b);
            c_sum += abs(a[i]-c);
        }
        if(b_sum<0) b_sum = LINF;
        if(c_sum<0) c_sum = LINF;
        ans = min(b_sum,c_sum);
    }else{
        int b = a[n/2];
        ll tmp=0;
        rep(i,n){
            tmp += abs(a[i]-b);
        }
        ans = tmp;
    }
    cout << ans << endl;
}