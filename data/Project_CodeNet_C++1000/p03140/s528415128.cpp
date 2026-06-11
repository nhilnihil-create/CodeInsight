#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    string A, B, C;
    cin >> N >> A >> B >> C;
    ll ans = 0;
    rep(i, 0, N){
        if(A[i] == B[i]){
            if(A[i] != C[i]) ans++;
        }else{
            if(A[i] == C[i] || B[i] == C[i]) ans++;
            else ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}