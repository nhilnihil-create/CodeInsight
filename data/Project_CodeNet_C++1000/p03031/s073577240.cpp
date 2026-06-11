#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

typedef long long ll;

void solve1()
{
    int n, m; cin >> n >> m;
    vector<int> k(m);
    vector<vector<int>> s(m);
    vector<int> p(m);
    for(int i = 0; i < m; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            int in; cin >> in;
            s[i].push_back(in);
        }
    }
    
    for(int i = 0; i < m; i++) {
        cin >> p[i];
    }

    int ans = 0;
   
    for(int i = 0; i < (1 << n); i++) {
        vector<int> ss;
        vector<bool> ps(n, false);
        int pos = 0;

        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                ps[j] = true;
            } 
        }

        for(int j = 0; j < m; j++) {
            int cnt = 0;
            for(int l = 0; l < k[j]; l++) {
                if(ps[s[j][l]-1]) {
                    cnt ++;
                }
            }

            if(cnt%2 == p[j]) {
                pos ++;
            }
        }

        if(pos == m) {
            ans ++;
        }
    }

    cout << ans << endl;


}

int main()
{
    solve1();
}
