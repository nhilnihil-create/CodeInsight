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
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll n, ans = 0; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    // +は繰り上がりがある、xorは繰り上がりが無い加算と考える
    ll left = 0, right = 0;
    ll sum = 0, xsum = 0;

    for(left = 0; left<n; left++){
        if(right == n) ans += right-left;
        else{
            while(sum == xsum && right < n){
                sum += a[right];
                xsum ^= a[right];
                right++;
            }
            if(sum != xsum){
                right--;
                sum -= a[right];
                xsum ^= a[right];
            }
            ans += (right - left);
            sum -= a[left];
            xsum ^= a[left];
        }
    }
    cout << ans << endl;
}