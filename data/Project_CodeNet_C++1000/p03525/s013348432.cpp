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

long long dt(const long long &a, const long long &b){
    long long bn = max(a, b);
    long long sn = min(a, b);
    return min(bn-sn, 24-bn+sn);
}

long long f(const vector<long long> &time){
    long long ret = INFLL;
    long long n = time.size();
    for(long long i=0; i<n; i++){
        for(long long j=i+1; j<n; j++){
            chmin(ret, dt(time[i], time[j]));
        }
    }
    return ret;
}

int main(){
    Init();
    long long n, ans = 0;
    cin >> n;
    map<ll, ll> cnt;
    bool chk3 = false;
    for(long long i=0; i<n; i++){
        long long d;
        cin >> d;
        cnt[d]++;
        if(cnt[d] >= 3) chk3 = true;
    }

    // ------------------------例外処理------------------------
    if(n == 1){
        cout << min((24 - cnt.begin()->first)%24, cnt.begin()->first) << endl;
        return 0;
    }

    if(n == 2 && cnt.size() == 1){
        long long t = cnt.begin()->first;
        long long rt = 24-t;
        cout << min(t, rt-t) << endl;
        return 0;
    }

    if(chk3 || cnt[0] >= 1){
        cout << 0 << endl;
        return 0;
    }
    // ------------------------例外処理------------------------

    // 12及び2個あるものの処理の処理
    vector<bool> f2(13, false);
    for(ll i=1; i<=11; i++){
        if(cnt[i] >= 2){
            cnt[i] = 0;
            f2[i] = true;
        }
    }
    f2[12] = (cnt[12] >= 1 ? true : false);
    if(f2[12]) cnt[12] = 0;

    // 残った時差を正・負の方向両方で全探索する
    vi num;
    for(ll i=1; i<=11; i++) if(cnt[i] >= 1) num.push_back(i);
    long long size = num.size();

    for(ll i=0; i<(1LL<<size); i++){
        vi time;
        time.push_back(0);
        if(f2[12]) time.push_back(12);
        for(ll i=1; i<=11; i++) if(f2[i]){ time.push_back(i); time.push_back(24-i); }

        for(ll mask=0; mask<size; mask++){
            if(i&(1LL<<mask)) time.push_back(24-num[mask]);
            else time.push_back(num[mask]);
        }
        chmax(ans, f(time));
    }

    cout << ans << endl;
}