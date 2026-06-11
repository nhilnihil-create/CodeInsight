#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

vector<int> p(100005);
vector<int> imos(100005);

int main() {
    int N, C; cin >> N >> C;
    vector<multiset<int> > cs(C);
    vector<multiset<int> > ct(C);
    rep(i, N){
        int s, t, c;
        cin >> s >> t >> c;
        c--;
        p[s]++;
        p[t+1]--;
        cs[c].insert(s);
        ct[c].insert(t);
        if(cs[c].find(t) != cs[c].end()){
            p[t]--;
            p[t+1]++;
        }
        if(ct[c].find(s) != ct[c].end()){
            p[s]--;
            p[s+1]++;
        }
    }
    rep(i, 100000){
        imos[i+1] = imos[i] + p[i+1];
    }

    int ans = 0;
    rep(i, 100001){
        ans = max(ans, imos[i]);
    }

    cout << ans << endl;

    return 0;
}