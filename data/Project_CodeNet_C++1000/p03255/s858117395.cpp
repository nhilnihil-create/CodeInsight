#include <bits/stdc++.h>
using namespace std;

int main(){
    int64_t N, X;
    cin >> N >> X;
    vector<int64_t> x(N+1), S(N+1);
    for(int i=1; i<=N; i++){
        cin >> x[i];
        S[i] = S[i-1] + x[i];
    }

    int64_t ans = 1e18;
    for(int d=1; d<=N; d++){
        int64_t res = (N+d)*X;
        int pt = N;
        for(int64_t i=0; pt>0; i++){
            int nxt = max(0, pt-d);
            res += (S[pt]-S[nxt]) * (i==0 ? 5 : 2*i+3);
            if(res >= ans) break;
            pt = nxt;
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
}