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
    ll n; cin >> n;
    // nが偶数の場合はn/2個、奇数の場合はn/2+1個のグループに分ける。
    // 偶数; (1, n), (2, n-1), ... ,(n/2, n/2+1)
    // 奇数; (1, n-1), (2, n-2), ..., ((n-1)/2, (n-1)/2+1), (n)
    // 異なるグループのノードを全て連結するようなグラフによって問題条件を満たすグラフを構築できる。
    ll invalid = (n%2 == 0 ? n+1 : n);
    vi ans_a, ans_b;
    for(ll i=1; i<=n; i++){
        for(ll j=i+1; j<=n; j++){
            if(i+j == invalid) continue;
            ans_a.push_back(i);
            ans_b.push_back(j);
        }
    }
    cout << ans_a.size() << endl;
    for(ll i=0; i<ans_a.size(); i++) cout << ans_a[i] << " " << ans_b[i] << endl;
}