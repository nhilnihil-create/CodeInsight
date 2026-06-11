#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) (v).begin(),(v).end()
using ll = long long;
using P = pair<int, int>;

int main(){
    int N;
    string S;
    cin >> N >> S;
    int now = 0;
    for (int i=1; i<N; i++) {
        if (S[i] == 'E') now++;
    }
    int ans = now;
    for (int i=1; i<N; i++) {
        int tmp = 0;
        if (S[i-1] == 'W') tmp++;
        if (S[i] == 'E') tmp--;
        now += tmp;
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}