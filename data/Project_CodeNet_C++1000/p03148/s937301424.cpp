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
    ll N, K;
    cin >> N >> K;
    vvi Sushi(N, vi(0));

    rep(i, N){
        ll t, d; cin >> t >> d; t--;
        Sushi[t].emplace_back(d);
    }
    rep(i, N) sort(all(Sushi[i]), greater<ll>());

    vi top, other;
    rep(i, N){
        if(Sushi[i].size() != 0){
            rep(j, Sushi[i].size()){
                if(j == 0) top.emplace_back(Sushi[i][j]);
                else other.emplace_back(Sushi[i][j]);
            }
        }
    }
    ll var = top.size();
    sort(all(top), greater<ll>()); top.emplace_back(-INFLL);
    sort(all(other), greater<ll>()); other.emplace_back(-INFLL);

    ll ans = 0, preans = 0, cnt = 0;
    ll pos_t = 0, pos_o = 0;
    while(cnt < K){
        if(top[pos_t] >= other[pos_o]){
            ans += top[pos_t];
            pos_t++;
        }
        else{
            ans += other[pos_o];
            pos_o++;
        }
        cnt++;
    }
    pos_o--;
    ans += (pos_t)*(pos_t);
    preans = ans;
    while(pos_t < K && pos_t < var){
        ll tmp = preans;
        tmp -= ((pos_t)*(pos_t) + other[pos_o]);
        tmp += top[pos_t] + (pos_t+1)*(pos_t+1);
        pos_t++; pos_o--;
        chmax(ans, tmp);
        preans = tmp;
    }
    cout << ans << endl;
}
