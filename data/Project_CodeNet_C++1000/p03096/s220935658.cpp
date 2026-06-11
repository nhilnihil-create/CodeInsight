#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;
const ll INF = 1001001001;

ll N, ans=0, tmp=0, DP[200001];
vector<ll> A, C[200001];

signed main(){
    cin >> N;
    DP[0]=1;
    for(int i=1;i<=N;i++) {
        ll a;
        cin >> a;
        DP[i] = DP[i-1];
        A.push_back(a);
        if(i==1) C[a].push_back(i);
        if(i>1) {
            if(A[i-2]!=A[i-1]) {
                if(C[a].size()>0) {
                    if(C[a].back()<i-1) DP[i] += DP[C[a].back()];
                }                
                C[a].push_back(i);
            }
        }
        DP[i] %= 1000000007;
        //cout << i << " " << DP[i] << endl;
    }
    cout << DP[N] << endl;
    return 0;
}