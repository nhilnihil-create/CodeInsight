#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<long long> > vvll;
typedef vector<pair<int, int> > vpii;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define INF 1000000000
#define MOD 1000000007
#define EPSILON 0.00001
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define p_q priority_queue

#define FOR(i, a, b) for (int i=(a); i<=(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define RFOR(i, a, b) for (int i=(a); i >= b; i--)

#define MN 100005
int n;
pii seg[MN];
pii seg2[MN];

bool comp1(pii a, pii b){
    if(a.s != b.s) return a.s < b.s;
    return a.f < b.f;
}
bool comp2(pii a, pii b){
    if(a.f != b.f) return a.f > b.f;
    return a.s > b.s;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    F0R(i, n){
        cin >> seg[i].f >> seg[i].s;
        seg2[i] = seg[i];
    }
    n++;
    sort(seg, seg+n, comp1);
    sort(seg2, seg2+n, comp2);

    ll ans = 0;
    int cur = 0;
    while(seg[cur].s < seg2[cur].f){
        ans += 2LL*(seg2[cur].f-seg[cur].s);
        cur++;
    }

    cout << ans << "\n";

    return 0;
}
