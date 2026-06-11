#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define reps(i, m, n) for (int i = m; i < n; i++)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(void){
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int> > switch_list(n, vector<int>(0, 0));
    int k, s;
    rep(i, m){
        scanf("%d", &k);
        rep(j, k){
            scanf("%d", &s);
            switch_list[s-1].push_back(i);
        }
    }
    
    vector<int> p(m, 0);
    rep(i, m) scanf("%d", &p[i]);
    
    int ans = 0;
    rep(i, pow(2, n)){
        vector<int> light(m, 0);
        rep(j, n){
            if ((i>>j)&1 == true){
                rep(k, switch_list[j].size()) light[switch_list[j][k]]++;
            }
        }
        bool judge = true;
        rep(j, m){
            if (light[j]%2 != p[j]) judge = false;
        }
        if (judge) ans++;
    }
    
    printf("%d\n", ans);
    
    return 0;
}
