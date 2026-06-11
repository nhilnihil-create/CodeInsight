#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    int cnt = 0;
    rep(i, N){
        if(s[i] == '#'){
            cnt++;
        }
    }

    int ans = cnt;
    vector<int> blk(N);
    vector<int> wht(N);
    for (int i = 1; i < N; i++){
        if(s[i-1] == '#'){
            wht[i] = wht[i-1]+1;
        } else {
            wht[i] = wht[i-1];
        }
    }

    if(s[N-1] == '.')blk[N-1] = 1;
    for (int i = N-2; i >= 0; i--){
        if(s[i] == '.'){
            blk[i] = blk[i+1] + 1;
        } else {
            blk[i] = blk[i+1];
        }
    }

    rep(i, N){
        int x = wht[i] + blk[i];
        ans = min(ans, x);
    }

    cout << ans << endl;

    return 0;
}