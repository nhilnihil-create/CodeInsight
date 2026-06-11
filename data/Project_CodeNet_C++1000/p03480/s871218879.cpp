#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define LINF 1000000000000000000
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef pair<int, int> P;
typedef pair<long long, long long> LLP;

int check(string S) {

    int N = S.length();
    int ans = N;
    rep(i,N) {
        if (S[i] == '1') {
            ans = min(ans, max(i, N - 1 - i));
        }
    }

    return ans;

}

int main() {

    string S;
    cin >> S;

    int N = S.length();
    int ans = check(S);

    rep(i,N) S[i] = (S[i] == '0' ? '1' : '0');
    ans = max(ans, check(S));

    cout << ans << endl;
    
    return 0;
}