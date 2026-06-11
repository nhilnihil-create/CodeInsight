#include <iostream>
#include <algorithm>
#define rep(i,n) for(ll i=0;i<n;i++)
typedef long long int ll;
const ll INF = 100100100100100100;
using namespace std;

ll N,C;
ll x[100100],v[100100];
ll gain_r[100100],gain_l[100100];
ll rui_r[100100],rui_l[100100];
ll max_r[100100],max_l[100100];

int main(){
    cin >> N >> C;
    x[0] = 0;
    v[0] = 0;
    rep(i,N){
        cin >> x[i+1] >> v[i+1];
    }
    x[N+1] = C;
    v[N+1] = 0;
    N+=2;
    gain_r[0] = 0;
    rep(i,N-1){
        gain_r[i+1] = v[i+1] - (x[i+1] - x[i]);
        rui_r[i+1] = rui_r[i] + gain_r[i+1];
        max_r[i+1] = max(max_r[i],rui_r[i+1]);
    }
    gain_l[N] = 0;
    for(ll i=N-1; i>0;i--){
        gain_l[i-1] = v[i-1] - (x[i] - x[i-1]);
        rui_l[i-1] = rui_l[i] + gain_l[i-1];
        max_l[i-1] = max(max_l[i],rui_l[i-1]);
    }
    /*
    rep(i,N){
        cerr << " " << rui_r[i] << endl;;
    }
    cerr << endl;
    for(ll i=N-1; i>=0;i--){
        cerr << " " << rui_l[i] << endl;;
    }
    cerr << endl;
    */
    ll ans = 0;
    //non U turn
    ans = max(ans,max_r[N]);
    ans = max(ans,max_l[0]);

    //U turn
    rep(i,N-1){
        ll tmp_score = rui_r[i];
        tmp_score -= x[i];
        tmp_score += max_l[i+1];
        ans = max(ans,tmp_score);
    }
    for(ll i=N-1; i>0;i--){
        ll tmp_score = rui_l[i];
        tmp_score -= C-x[i];
        tmp_score += max_r[i-1];
        ans = max(ans,tmp_score);
    }
    cout << ans << endl;
}