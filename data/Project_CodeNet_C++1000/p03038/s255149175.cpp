#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> vec(N);
    rep(i,N){
        cin >> vec[i];
    }
    vector<pair<ll,ll> > combi(M);
    rep(i,M){
        cin >> combi[i].first >> combi[i].second;
    }
    vector<pair<ll,ll> > ans_vec(0);
    rep(i,N){
        ans_vec.push_back(pair<ll,ll>(vec[i],1));
    }
    rep(i,M){
        ans_vec.push_back(pair<ll,ll>(combi[i].second, combi[i].first));
    }
    sort(all(ans_vec));
    ll len = ans_vec.size();
    ll ans = 0;
    ll cnt = 0;
    for (ll i = len - 1; i >= 0; i--){
        if (cnt + ans_vec[i].second <= N){
            ans += ans_vec[i].first * ans_vec[i].second;
            cnt += ans_vec[i].second;
        }
        else{
            ans += ans_vec[i].first * (N - cnt);
            cnt = N;
        }
    }
    cout << ans << endl;
}
