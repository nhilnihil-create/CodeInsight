#include <bits/stdc++.h>
using namespace std;
#define int long long
int INF = 1e9+7;
signed main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int>cnt(26,1);
    for(int i = 0; i < N; i++) {
        cnt[S[i]-'a']++;
    }
    int res = 1;
    for(int i = 0; i < 26; i++) {
        res*=cnt[i];
        res = res%INF;
    }
    cout << res-1 << endl;
}