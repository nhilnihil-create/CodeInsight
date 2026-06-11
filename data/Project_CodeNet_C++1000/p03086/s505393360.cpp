#include <bits/stdc++.h>

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

using ll = long long;
using namespace std;

int main(){
    int cnt = 0,ans=0;
    string S;
    cin >> S;

    rep(i,S.length()){
        if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T'){
            cnt++;
        }else{
            cnt = 0;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}
