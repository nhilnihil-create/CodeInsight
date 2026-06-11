#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,M;
    cin >> N >> M;
    vector<ll> x(N);
    vector<ll> y(N);
    vector<ll> z(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> z[i];
    }
    vector<ll> vec0(N);
    rep(i,N){
        vec0[i] = x[i] + y[i] + z[i];
    }
    vector<ll> vec1(N);
    rep(i,N){
        vec1[i] = x[i] + y[i] - z[i];
    }
    vector<ll> vec2(N);
    rep(i,N){
        vec2[i] = x[i] - y[i] + z[i];
    }
    vector<ll> vec3(N);
    rep(i,N){
        vec3[i] = x[i] - y[i] - z[i];
    }
    vector<ll> vec4(N);
    rep(i,N){
        vec4[i] = -1 * x[i] + y[i] + z[i];
    }
    vector<ll> vec5(N);
    rep(i,N){
        vec5[i] = -1 * x[i] + y[i] - z[i];
    }
    vector<ll> vec6(N);
    rep(i,N){
        vec6[i] = -1 * x[i] - y[i] + z[i];
    }
    vector<ll> vec7(N);
    rep(i,N){
        vec7[i] = -1 * x[i] - y[i] - z[i];
    }
    sort(all(vec0));
    sort(all(vec1));
    sort(all(vec2));
    sort(all(vec3));
    sort(all(vec4));
    sort(all(vec5));
    sort(all(vec6));
    sort(all(vec7));
    ll ans = 0;
    ll ans_sub0 = 0;
    ll ans_sub1 = 0;
    ll ans_sub2 = 0;
    ll ans_sub3 = 0;
    ll ans_sub4 = 0;
    ll ans_sub5 = 0;
    ll ans_sub6 = 0;
    ll ans_sub7 = 0;
    rep(i,M){
        ans_sub0 += vec0[N - i - 1];
        ans_sub1 += vec1[N - i - 1];
        ans_sub2 += vec2[N - i - 1];
        ans_sub3 += vec3[N - i - 1];
        ans_sub4 += vec4[N - i - 1];
        ans_sub5 += vec5[N - i - 1];
        ans_sub6 += vec6[N - i - 1];
        ans_sub7 += vec7[N - i - 1];
    }
    ans = max(ans_sub0, max(ans_sub1, max(ans_sub2, max(ans_sub3, max(ans_sub4, max(ans_sub5, max(ans_sub6, ans_sub7)))))));
    cout << ans << endl;
}
