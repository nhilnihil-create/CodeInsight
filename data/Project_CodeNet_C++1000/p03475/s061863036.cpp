#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, tmp=0;
vector<ll> C(MAXN, 0), S(MAXN, 0), F(MAXN, 0), ans;

signed main(){
    cin >> N;
    for(int i=0;i<N-1;i++) cin >> C[i] >> S[i] >> F[i];
    ans.push_back(0);
    for(int i=N-2;i>=0;i--) {
        tmp = S[i] + C[i];
        for(int j=i+1;j<=N-2;j++) {
            if(max(tmp, S[j])%F[j]==0) tmp = max(tmp, S[j]) + C[j];
            else tmp = ((max(tmp, S[j])/F[j]+1)*F[j]) + C[j];
        }
        ans.push_back(tmp);
    }
    for(int i=ans.size()-1;i>=0;i--) {
        cout << ans[i] << endl;
    }
    return 0;
}