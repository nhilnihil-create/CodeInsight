#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int k; cin >> k;
    vector<ll> data(k); rep(i,k) cin >> data[i];

    ll mmin = 2, mmax = 2;
    bool check = true;
    for(int i = k-1; i >= 0; i--){
        ll x = (mmin+data[i]-1)/data[i];
        ll y = mmax/data[i];
        if(x > y){ check = false; break; }
        mmin = x*data[i];
        mmax = y*data[i] + (data[i]-1);
    }
    if(check) cout << mmin << " " << mmax << endl;
    else cout << -1 << endl;
}

