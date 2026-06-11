#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    ll N, M; cin >> N >> M;
    string s, t; cin >> s >> t;
    ll ans = (N * M) / __gcd(N, M);
    ll x = ans / N;
    ll y = ans / M;
    ll nowx = 0;
    ll nowy = 0;
    while(nowx < M && nowy < N){
        if(s[nowy] != t[nowx]){
            cout << -1 << endl;
            return 0;
        }
        nowx += x;
        nowy += y;
    }

    cout << ans << endl;

    return 0;
}