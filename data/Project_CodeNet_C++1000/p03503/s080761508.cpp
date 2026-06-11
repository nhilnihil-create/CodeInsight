#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<vector<vector<int> > > f;
vector<vector<ll> > p;
vector<int> v;

ll dfs(int i) {
    if (i == 10) {
        if (v.size() == 0)
            return -1*(ll)1e15;

        ll tmp = 0;
        vector<int> c(n, 0); //c[i]は店iとかぶっている時間帯の個数
        for (auto x: v) {
            int j = x/2, k = x%2;
            for (int l = 0; l < n; l++) {
                if (f[l][j][k])
                    c[l]++;
            }
        }
        for (int l = 0; l < n; l++)
            tmp += p[l][c[l]];
        return tmp;
    }

    
    v.push_back(i);
    ll res = dfs(i+1);
    v.pop_back();
    res = max(res, dfs(i+1));

    return res;
}

int main() {
    cin >> n;
    f.resize(n, vector<vector<int> >(5, vector<int>(2)));
    p.resize(n, vector<ll>(11));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++)
            cin >> f[i][j][0] >> f[i][j][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 11; j++)
            cin >> p[i][j];
    }

    cout << dfs(0) << endl;
    return 0;
}