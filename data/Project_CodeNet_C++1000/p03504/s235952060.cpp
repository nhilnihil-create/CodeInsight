#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main() {
    int N,C,s,t,c,r=0;
    cin >> N >> C;
    vector<vector<int>> tt(100010, vector<int>(C,0));
    set<int> p;

    rep(i,N) {
        cin >> s >> t >> c;
        tt.at(--s).at(--c) += 1;
        tt.at(t).at(c) += 1;
    }

    rep(i,100010) {
        rep(j,C)
            if(tt.at(i).at(j)%2)
                if(p.count(j))
                    p.erase(j);
                else
                    p.insert(j);
        r = max(r, (int)p.size());
    }

    cout << r << endl;
}