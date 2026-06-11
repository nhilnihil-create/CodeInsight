#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<ll> S(5);
    rep(i, N){
        string s; cin >> s;
        if(s[0] == 'M'){
            S[0]++;
        } else if(s[0] == 'A'){
            S[1]++;
        } else if(s[0] == 'R'){
            S[2]++;
        } else if(s[0] == 'C'){
            S[3]++;
        } else if(s[0] == 'H'){
            S[4]++;
        }
    }

    ll ans = (S[0] * S[1] * (S[2]+S[3]+S[4])) + (S[0] * S[2] * (S[3]+S[4])) + (S[0] * S[3] * S[4]);
    ans += (S[1] * S[2] * (S[3] + S[4])) + (S[1] * S[3] * S[4]) + (S[2] * S[3] * S[4]);

    cout << ans << endl;



    return 0;
}