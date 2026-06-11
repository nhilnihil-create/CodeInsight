#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll N, ans=10000000000, tmp=0;
vector<ll> A, B;
string S;
signed main(){
    cin >> N >> S;
    A.resize(N+1);
    B.resize(N+1);
    A[0] = 0;
    B[N]=0;
    for(int i=1;i<=N;i++) {
        if(S[i-1]=='#') A[i] = A[i-1] + 1;
        else A[i] = A[i-1];
    }
    for(int i=N-1;i>=0;i--) {
        if(S[i+1]=='.') B[i] = B[i+1] + 1;
        else B[i] = B[i+1];
    }
    for(int i=0;i<=N;i++) {
        ans = min(ans, A[i]+B[i]);
    }
    cout << ans << endl;
    return 0;
}