#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// 空白がある位置を二分探索で絞り込んでいく
int main(){
    ll n; cin >> n;
    vector<string> mw(n);

    cout << 0 << endl;
    cin >> mw[0];
    if(mw[0] == "Vacant") return 0;
    cout << n-1 << endl;
    cin >> mw[n-1];
    if(mw[n-1] == "Vacant") return 0;

    ll l = 0, r = n-1;
    for(ll i=0; i<20; i++){
        ll mid = (l+r)/2;
        cout << mid << endl;
        cin >> mw[mid];
        if(mw[mid] == "Vacant") return 0;
        if((((mid-l+1)%2 == 0) && (mw[l] == mw[mid])) || (((mid-l+1)%2 == 1) && (mw[l] != mw[mid]))) r = mid;
        else l = mid;
    }
    return 0;
}