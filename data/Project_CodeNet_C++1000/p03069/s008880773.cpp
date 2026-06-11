#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    vector<ll> B(N+1), W(N+1);
    if(S[0] == '#')B[1]=1;
    if(S[N-1] == '.') W[N-1] = 1;
    for(int i = 2; i <= N; i++){
        B[i] = B[i-1];
        if(S[i-1] == '#') B[i]++;
    }
    for(int i = N-2; i >= 0; i--){
        W[i] = W[i+1];
        if(S[i] == '.') W[i]++;
    }
    ll ans = 1000000000;
    for(int i = N-1; i >=0; i--){
        ll tmp = 1000000000;
        tmp = B[i] + W[i+1];
        ans = min(ans, tmp);

    }

    cout << ans << endl;
}