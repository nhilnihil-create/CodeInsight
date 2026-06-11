#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;
typedef long long ll;
int main(){
    int n,k;
    cin  >> n >> k;
    vector<ll > a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll> b;
    rep(i,n){
        ll s = 0;
        for(int j = i;j<n;j++){
            s+=a[j];
            b.push_back(s);
        }
    }
    ll ans = 0;
    ll t = 1;
    rep(i,50){
        t*=2;
    }
    rep(i,52){
        int cnt = 0;
        for(auto j:b){
            if(((ans+t)&j)==ans+t){
                cnt++;
            }
        }
        if(cnt>=k){
            ans+=t;
        }
        t/=2;
    }
    cout << ans << endl;
    return 0;
}