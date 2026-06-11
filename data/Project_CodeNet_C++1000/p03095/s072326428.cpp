#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> cnt(26, 0);
    for (int i = 0; i < N; i++) {
        cnt[ S[i] - 'a' ]++;
    }
    ll ans = 1;
    for (int i = 0; i < 26; i++) {
        ans = ans * (cnt[i] + 1) % MOD;
    }
    ans--;
    printf("%lld\n", ans);
}