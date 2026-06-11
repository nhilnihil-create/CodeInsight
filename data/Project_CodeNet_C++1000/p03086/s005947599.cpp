#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;



int main(){
    string S; cin >> S;
    ll ans = 0;
    vector<char> C = {'A', 'T', 'G', 'C'};
    for(int i = 0; i < S.size(); i++){
        ll cnt = 0;
        
        while(i < S.size() && find(C.begin(), C.end(), S[i]) != C.end()){
            i++;
            cnt++;
        }
        if(cnt) i--;
        ans = max(ans, cnt);
    }
    cout << ans << endl;

} 
