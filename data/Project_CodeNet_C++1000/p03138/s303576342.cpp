#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;

int n;
ll k;
vector<ll> score_0(100);
vector<ll> score_1(100);
vector<ll> i_cost(100);
vector<ll> i_score(100);

ll solve(ll cost, ll score, int d) {
    ll c = 1ll<<d;
    if(d==0) {
        if(cost + 1ll > k) return score + score_0[0];
        else return score + i_score[0];
    }
    if(cost + c <= k) {
        return max(solve(cost+c, score+score_1[d], d-1), score+score_0[d]+i_score[d-1]);
    }
    else return solve(cost, score+score_0[d], d-1);
}

int main() {
    cin >> n >> k;
    rp(i, 0, n) {
        ll a; scanf("%lld", &a);
        ll s = 1ll;
        rp(j, 0, 50) {
            if(s & a) score_0[j] += s;
            else score_1[j] += s;
            s*=2;
        }
    }
    if(score_0[0] < score_1[0]){
        i_score[0] = score_1[0];
        i_cost[0] = 1ll;
    }
    else i_score[0] = score_0[0];
    rp(i, 1, 50) {
        if(score_0[i] < score_1[i]) {
            i_score[i] = i_score[i-1] + score_1[i];
            i_cost[i] = i_cost[i-1] + (1ll<<i); 
        }
        else {
            i_score[i] = i_score[i-1] + score_0[i];
            i_cost[i] = i_cost[i-1];
        }
        // printf("i = %d score_0 = %lld score_1 = %lld i_score=%lld i_cost=%lld\n", i, score_0[i], score_1[i], i_score[i], i_cost[i]);
    }
    cout << solve(0ll, 0ll, 50) << endl;
    return 0;
}

