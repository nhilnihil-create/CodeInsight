#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long

const int MOD =  1000000007;
const int IINF = INT_MAX;
const ll INF = 1LL << 60;


int main() {
    int n, m; cin >> n >> m;
    map<int, set<int> > mp;
    V<P<int, int> > v(m);
    for(int i = 0; i < m; i++){
        int p, y; cin >> p >> y;
        mp[p].insert(y);
        v[i] = make_pair(p, y);
    }

    map<int, int> mp2;
    for(auto p : mp){
        int i = 1;
        for(auto s : p.second){
            mp2[s] = i;
            i++;
        }
    }

    for(int i = 0; i < m; i++){
        printf("%06d%06d", v[i].first, mp2[v[i].second]);
        cout << "\n";
    }


    return 0;
}
