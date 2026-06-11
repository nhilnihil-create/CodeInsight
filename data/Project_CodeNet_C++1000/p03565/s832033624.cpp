#include<bits/stdc++.h>
// #define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
#define MOD 1000000007
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)

string ss, T;

string solve(){
    int N = ss.length();
    int M = T.length();

    set<string> ans;
    /* N ~ Mまで */
    rrep(R, N, M){
        int L = R - M;

        int ok = 1;
        rep(i, M) if(ss[L+i] != '?' && ss[L+i] != T[i]) ok = 0;
        if(ok){
            string S;
            rep(i, N) S += ss[i];
            rep(i, M) S[L+i] = T[i];
            rep(i, N) if(S[i] == '?') S[i] = 'a';
            ans.insert(S);
        }
    }

    if(ans.size() == 0) return "UNRESTORABLE";
    return *(ans.begin());
}

signed main(){
    cin >> ss >> T;
    cout << solve() << endl;
}