#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()
ll d1[4] = {1, -1, 0, 0};
ll d2[4] = {0, 0, 1, -1};

int main(){
    ll N, H;
    cin >> N >> H;
    VP p(N);
    ll mxa = 0;
    rep(i, 0, N){
        cin >> p[i].second >> p[i].first;
        mxa = max(mxa, p[i].second);
    }
    sort(ALL(p), greater<PL>());
    cerr << "foo" << endl;
    VL sum;
    ll i = 0, now = 0;
    while(p[i].first > mxa && i < N){
        sum.push_back(now + p[i].first);
        now += p[i].first;
        i++;
    }
    cerr << "hoge" << endl;
    ll r = sum.size();
    ll L = 0, R = 1e9+1;
    while(R - L > 1){
        ll M = L + (R - L) / 2;
        ll mx;
        if(r == 0){
            mx = mxa * M;
        }else if(M <= r){
            mx = sum[M-1];
        }else{
            mx = sum[r-1] + mxa * (M - r);
        }
        if(mx >= H) R = M;
        else L = M;
    }
    cout << R << endl;
    return 0;
}