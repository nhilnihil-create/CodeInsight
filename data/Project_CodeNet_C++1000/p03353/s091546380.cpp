#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e8;
const ll INF = 1e16;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();
    set<string> s;
    //i文字の連続する部分文字列を全列挙
    rep2(i, 1, K){
        rep(j, N+1-i){
            string tmp = "";
            rep(k, i) tmp = tmp+S[j+k];
            s.insert(tmp);
        }
    }
    int i = 0;
    for(auto &e: s){
        i++;
        if(i == K) cout << e << endl;
    }
}