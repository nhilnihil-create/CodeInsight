#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
string S;
int Macc[1000100];
int Cacc[1000100];
int MC[1000100];
int MCacc[1000100];
int Q;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    cin >> S;
    Macc[0] = 0;
    Cacc[0] = 0;
    rep(i, N) {
        if (S[i]=='M') Macc[i+1] = Macc[i]+1;
        else Macc[i+1] = Macc[i];
        if (S[i]=='C') Cacc[i+1] = Cacc[i]+1;
        else Cacc[i+1] = Cacc[i];
    }
    MCacc[0] = 0;
    rep(i, N) {
        if (S[i]=='C') MC[i] = Macc[i];
        else MC[i] = 0;
        MCacc[i+1] = MCacc[i]+MC[i];
    }
    
    cin >> Q;
    while (Q--) {
        int k; cin >> k;
        int ans = 0;
        int M = 0;
        rep(i, N) {
            int j = min(N, i+k);
            if (S[i]=='D') ans += MCacc[j]-MCacc[i+1]-(Cacc[j]-Cacc[i+1])*M;
            else if (S[i]=='M') M++;
        }
        cout << ans << endl;
    }
}