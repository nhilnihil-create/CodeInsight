#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
    bool hantei=true;
    int n,m;
    cin >> n;
    vector<ll> d(n);
    rep(i,n) cin >> d[i];
    cin >> m;
    vector<ll> t(m);
    rep(i,m) cin >> t[i];
    
    map<ll,int> cnt_d;
    map<ll,int> cnt_t;
    rep(i,n) cnt_d[d[i]]++;
    rep(i,m) cnt_t[t[i]]++;
    
    rep(i,m){
        if(cnt_d[t[i]] < cnt_t[t[i]]) hantei = false;
    }
    if(hantei) cout << "YES" <<endl;
    else    cout << "NO" <<endl;


}