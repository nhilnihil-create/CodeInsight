#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> pre;
    ll mx = 55555;
    vector<bool> v(mx+1, false);
    rep(i, 2, mx+1){
        if(v[i]) continue;
        if(i % 5 == 2) pre.push_back(i);
        for(ll j = i; j <= mx; j += i) v[j] = true;
    }
    cerr << pre.size() << endl;
    rep(i, 0, N) cout << pre[i] << " ";
    cout << endl;
    return 0;
}