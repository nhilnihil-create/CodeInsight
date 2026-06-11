#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL (1LL<<62) // 9223372036854775807
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
    // 初期入力
    Init();
    ll n;
    cin >> n;
    vi a(n);
    map<ll, ll> cnt;
    pair<ll, ll> maxNum = {-INFLL, -1}, minNum = {INFLL, -1};
    rep(i, n){
        cin >> a[i];
        cnt[a[i] == 0 ? 0 : a[i]/abs(a[i])]++;
        if(a[i] > maxNum.first) maxNum = make_pair(a[i], i);
        if(a[i] < minNum.first) minNum = make_pair(a[i], i);
    }

    // 操作の記録
    vector<pair<ll, ll>> ans;

    // 正と負の値が混在している場合
    if(cnt[1] != 0 && cnt[-1] != 0){
        // 初期要素のうち、最大値の絶対値が最小値の絶対値より大きい場合は、
        // 全ての要素に最大値を加算することで全て正にできる
        if(abs(maxNum.first) >= abs(minNum.first)){
            for(ll i=0; i<n; i++) if(i != maxNum.second) ans.emplace_back(maxNum.second, i);
            ans.emplace_back(maxNum.second, maxNum.second);
            cnt[1] = n, cnt[-1] = 0, cnt[0] = 0;
        }
        // 最大値の絶対値より最小値の絶対値のほうが大きいまたは等しい場合は、
        // 全ての要素に最小値（負値）を加算することで負or0にできる
        else{
            for(ll i=0; i<n; i++) if(i != minNum.second) ans.emplace_back(minNum.second, i);
            ans.emplace_back(minNum.second, minNum.second);
            cnt[1] = 0, cnt[-1] = n, cnt[0] = 0;
        }
    }

    // 正なら先頭から、負なら末尾から累積和を求める
    if(cnt[1] + cnt[0] == n) for(ll i=0; i<n-1; i++) ans.emplace_back(i, i+1);
    else for(ll i=n-1; i>=1; i--) ans.emplace_back(i, i-1);

    // 答えの出力
    cout << ans.size() << endl;
    for(ll i=0; i<(ll)ans.size(); i++){
        cout << ans[i].first+1 << " " << ans[i].second+1 << endl;
        a[ans[i].second] += a[ans[i].first];
    }
}