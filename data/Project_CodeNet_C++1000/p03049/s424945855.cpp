#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll N; cin >> N;
    ll ans = 0;
    ll b=0, a=0;
    ll cnt=0;
    vector<string> V(N);
    for(int i = 0; i < N; i++){
        string S; cin >> S;
        for(int j = 0; j < S.size()-1; j++){
            if(S[j] == 'A' && S[j+1] == 'B') ans++;
        }
        if(S[0] == 'B') b++;
        if(S[(int)S.size()-1] == 'A') a++;
        if(S[0] == 'B' && S[(int)S.size()-1] == 'A') cnt++;

    }
    if( cnt != 0 && cnt == a && cnt == b) cout << ans + min(a, b) -1 << endl;
    else if(cnt == 1 && a == 1 && b == 1) cout << 0 << endl;
    else if(cnt == N) cout << ans+min(a, b)-1 << endl;
    else cout << ans+min(a, b) << endl;

}