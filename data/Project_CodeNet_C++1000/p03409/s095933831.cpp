#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int INF = 10000;

int main() {
    int N; cin >> N;
    vector<P> R(N);
    vector<P> B(N);
    bool use[N];
    rep(i, N){
        use[i] = false;
    }
    rep(i, N){
        int a, b; cin >> a >> b;
        R[i] = make_pair(a, b);
    }
    rep(i, N){
        int c, d; cin >> c >> d;
        B[i] = make_pair(c, d);
    }
    sort(R.begin(), R.end());
    sort(B.begin(), B.end());

    rep(i, N){
        int c = B[i].first;
        int x = INF;
        int b = -1;
        int n = 0;
        while(1){
            if(n == N)break;
            if(use[n]){
                n++;
                continue;
            }
            int a = R[n].first;
            if(a > c)break;
            if(R[n].second < B[i].second){
                if(R[n].second > b){
                    b = R[n].second;
                    x = n;
                }
            }
            n++;
        }
        if(x == INF)continue;
        use[x] = true;
    }

    int ans = 0;
    rep(i, N){
        if(use[i])ans++;
    }

    cout << ans << endl;

    return 0;
}