#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    string S;
    cin >> N >> S;
    // 白を黒に変えるときの数
    vector<ll> right(N+1,0);
    for(int i=0;i<N;i++){
        right[i+1] += right[i];
        if(S[i] == '#'){
            right[i+1]++;
        }
    }
    vector<ll> left(N+1,0);
    for(int i=N-1;i>=0;--i){
        left[i] += left[i+1];
        if(S[i] == '.'){
            left[i]++;
        }
    }

    ll ans = N;
    for(int i=0;i<=N;i++){
        ans = min(ans,right[i]+left[i]);
    }
    cout << ans << endl;

    return 0;
}
