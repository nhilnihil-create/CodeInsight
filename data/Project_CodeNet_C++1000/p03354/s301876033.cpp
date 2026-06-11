#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using Graph = vector<vector<int>>;

int c=0;
vector<bool> seen;
vector<vector<int>> s;

void dfs(const Graph &G, int v) {
    seen.at(v) = 1;
    for(auto nv : G.at(v)) {
        if(seen.at(nv))
            continue;
        s.at(c).push_back(nv);
        dfs(G, nv);
    }
}

int main() {
    int N,M,x,y,r=0;
    cin >> N >> M;
    vector<int> p(N);
    Graph G(N);
    vector<set<int>> st(N);

    rep(i,N)
        cin >> p.at(i);

    rep(i,M) {
        cin >> x >> y;
        --x, --y;
        G.at(x).push_back(y);
        G.at(y).push_back(x);
    }

    seen.assign(N, 0);
    s.assign(N, vector<int>());
    rep(i,N) {
        if(seen.at(i))
            continue;
        s.at(c).push_back(i);
        dfs(G, i);
        ++c;
    }

    rep(i,N) {
        if(s.at(i).size() == 0)
            break;
        rep(j,s.at(i).size())
            st.at(i).insert(p.at(s.at(i).at(j)));
    }
    
    rep(i,N) {
        if(s.at(i).size() == 0)
            break;
        rep(j,s.at(i).size())
            if(st.at(i).count(s.at(i).at(j)+1))
                ++r;
    }

    cout << r << endl;
}