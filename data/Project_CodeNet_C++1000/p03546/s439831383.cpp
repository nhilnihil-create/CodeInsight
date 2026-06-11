#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define vi vector<int>
#define vl vector<long long>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPD(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define FORD(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define INF 1e18
#define MOD 1e9+7

template<class T> bool chmax(T &a, const T & b) {
    if (a<b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool chmin(T &a, const T & b) {
    if (a>b) {
        a = b;
        return true;
    }
    return false;
}

const int MAX_N = 110;
struct edge {int to, cost;};
vector< vector<edge> > es;
ll d[10][10];
int cnt[10];
int H, W;

void warshallfloyd() {
    REP(j, 10) {
        REP(i, 10) {
            REP(k, 10) {
                chmin(d[i][k], d[i][j]+d[j][k]);
            }
        }
    }
}

int main() {
    cin >> H >> W;
    REP(i, 10) {
        REP(j, 10) {
            cin >> d[i][j];
        }
    }
    
    memset(cnt, 0, sizeof(cnt));
    REP(i, H) {
        REP(j, W) {
            int ind;
            cin >> ind;
            if (ind == -1) continue;
            cnt[ind] += 1;
        }
    }
	
    warshallfloyd();
    int ans = 0;
    REP(i, 10) {
        ans += cnt[i]*d[i][1];
    }
    cout << ans << endl;
    return 0;
}      