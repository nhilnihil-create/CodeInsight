#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
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

// 反転回数の記録用
ll rp = 0;

// 連長圧縮（ランレングス圧縮）：sの連長部分を{文字,個数}の配列で返す
vector<pair<char, long long>> rle(string s){
    vector<pair<char, long long>> ret;
    long long i = 0, n = s.size();
    while(i<n){
        char tmp = s[i];
        long long cnt = 1;
        while(i<n){
            i++;
            if(tmp == s[i]) cnt++;
            else break;
        }
        if(tmp == '0') rp++;
        ret.push_back(make_pair(tmp, cnt));
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    ll n, k, ans = 0; string s; cin >> n >> k >> s;

    // ランレングス圧縮
    auto rlev = rle(s);

    // 全部反転できる場合
    if(k >= rp){ cout << n << endl; return 0; }

    // 0の列をk個反転させた場合の長さを全探索
    ll rcnt, sum, cur, prev_sum = 0;
    rep(i, rlev.size()){
        // 初回のみ先頭から0の列をk個反転させた場合の長さ
        if(i == 0) rcnt = 0, sum = 0, cur = i;
        else{
            // 2回目以降は先頭の列分を引いて計算時間を短縮
            if(rlev[i-1].first == '0') rcnt--;
            sum -= rlev[i-1].second;
        }
        // k回反転するまで長さを足し合わせる
        while(cur<rlev.size()){
            if(rlev[cur].first == '0' && rcnt >= k) break;
            else{
                sum += rlev[cur].second;
                if(rlev[cur].first == '0') rcnt++;
                cur++;
            }
        }
        // 最大値を出力用変数に格納
        chmax(ans, sum);
    }
    cout << ans << endl;
}