#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> blacksum(N+1), whitesum(N+1);
    for (int i=0;i<N;i++){
        if (S[i] == '#'){
            blacksum[i+1]=blacksum[i]+1;
            whitesum[i+1]=whitesum[i];
        }else {
            blacksum[i+1]=blacksum[i];
            whitesum[i+1]=whitesum[i]+1;
        }
    }
    int ans = INF;
    for (int i=0;i<=N;i++){
        int p=blacksum[i];
        int q=whitesum[N]-whitesum[i];
        int r = p+q;
        ans = min(ans, r);
    }
    cout << ans << "\n";
}