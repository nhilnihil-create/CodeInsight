#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = LLONG_MAX, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W;
typedef long long ll;
typedef pair<ll, ll> Pa;
typedef pair<Pa, ll> info;

info infos[100];
int main() {
	cin >> N;
    ll min_h = 1e9, max_h = 0;
    rep(i, N){
        cin >> A >> B >> C;
        infos[i] = info(Pa(A, B), C);
        min_h = min(min_h, C);
        max_h = max(max_h, C);
    }
    rep(x, 101){
        rep(y, 101){
            for(ll h = max_h; h<min_h + 201;h++){
                bool flag = true;
                rep(i, N){
                    flag &= (max(0ll, (h - abs(infos[i].first.first - x) - abs(infos[i].first.second - y))) == infos[i].second);
                }
                if(flag){
                    cout << x << " " << y << " " << h;
                    return 0;
                }
            }
        }
    }
}
