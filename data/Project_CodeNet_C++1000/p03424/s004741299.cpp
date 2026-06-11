#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MOD = 1000000007;


int main(){
    int N;
    cin >> N;
    vector<char> S(N);
    rep(i,N) cin >> S[i];

    string ans = "Three";
    rep(i,N){
        if (S[i] == 'Y') {
            ans = "Four";
        }
    }

    cout << ans << endl;
}
