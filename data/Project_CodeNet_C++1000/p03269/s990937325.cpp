#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000

typedef pair<int, int> P;
vector<P> v[61];
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int L; cin >> L;
    int V = 0;
    int t = L;
    while(t > 0) {
        V++;
        t /= 2;
    }
    int m = 0;
    rep(i, (V - 1)) {
        v[i + 2].push_back({i + 1, 0});
        v[i + 2].push_back({i + 1, (1 << i)});
        m += 2;
    }
    int num = (1 << (V - 1));

    RREP(i, V - 2, 0) {
        if(L & (1 << i)) {
            v[V].push_back({i + 1, num});
            num += (1 << i);
            m++;
        }
    }
    //v[V].push_back({1, num});
    //m++;
    //cout << num << endl;
    cout << V << " " << m << endl;
    rep(i, V) {
        for(auto& e: v[i + 1]) {
            cout << e.first << " " << i + 1 << " " << e.second << endl;
        }
    }


    return 0;
}
