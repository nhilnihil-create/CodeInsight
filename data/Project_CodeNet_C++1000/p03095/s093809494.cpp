#include <bits/stdc++.h>
using namespace std;

#define rep(i, a) for (int i = 0; i < (a); i++ )
#define FOR(i, m, n) for(int i = m; i < n; i++)
 
typedef pair<int,int> P;
typedef long long ll;
 
const int INF = 1001001001;
const int MOD = 1000000007;
const double PI=acos(-1);


int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;

    map<char,int> A;
    rep(i,N) {
        char tmp = S[i];
        A[tmp]++;
    }

    ll ans = 1;

    for (auto a: A){
        auto n = a.second;

        ans *= n+1;
        ans %= MOD;
    }

    ans = (ans-1)%MOD;
    cout << ans << endl;    
}