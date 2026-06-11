#include <bits/stdc++.h>

#define FOR(i, l, r) for(ll i = l; i < r; i++)
#define rep(i, N) FOR(i, 0, N)

#define MOD 1000000007
#define INF 1000000000

using ll = long long int;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    string S; cin >> S;
    string T; cin >> T;
    string ans;

    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());

    int tmp = INF;
    rep(i,S.size()){
        bool flag = true;
        rep(j,T.size()) {
            if(i+j > (int)S.size()-1 || (S[i+j] != T[j] && S[i+j] != '?')) {
                flag = false;
                break;
            }
        }
        if(flag) {
            tmp = i;
            break;
        }
    }

    if(tmp == INF){
        cout << "UNRESTORABLE";
        return 0;
    }

    rep(i,S.size()){
        if(i < tmp || i > tmp + (int)T.size() -1){
            ans += (S[i]!='?'?S[i]:'a');
        } else {
            ans += T[i-tmp];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}
