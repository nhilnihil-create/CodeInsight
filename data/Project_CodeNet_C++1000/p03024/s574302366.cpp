#include <bits/stdc++.h>
using namespace std;
#define INF 2147483647
#define INFF 9223372036854775807
#define ll long long
#define REP(i,n) for(int i=0;i<n;i++)
#define REPP(i,m,n) for(int i=m;i<n;i++)
#define ALL(N) (N.begin(),N.end())
#define de cout << "debug" << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    string S;
    cin >> S;
    int ans = 0;
    ans += (15-S.size());

    REP(i,S.size()){
        if(S[i] == 'o'){
            ans++;
        }
    }

    if(ans >= 8) cout << "YES" << endl;
    else cout << "NO" << endl;
}