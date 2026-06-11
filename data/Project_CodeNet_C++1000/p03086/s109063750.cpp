#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(ll i = l; i < (ll)(r); i++)
#define rep(i, N) FOR(i, 0, N)
#define ALL(x) x.begin(),x.end()

typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
const ll MOD = 1000000007LL;

int main() {
    string S; cin >> S;
    int ans = 0,tmp = 0;
    rep(i,(ll)S.size()){
        if(S[i] == 'A'||S[i] == 'C'
        || S[i] == 'G'||S[i] == 'T'){
            tmp++;
        }else{
            tmp = 0;
        }
        ans = max(ans,tmp);
    }

    cout << ans << "\n";
    return 0;
}
