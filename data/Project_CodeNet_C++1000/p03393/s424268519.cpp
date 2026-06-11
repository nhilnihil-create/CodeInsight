#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    string S;
    cin >> S;
    if(S == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }
    if(S.size() < 26) {
        vector<int>cnt(26);
        for(int i = 0; i < S.size(); i++) {
            cnt[S[i]-'a']++;
        }
        cout << S;
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) {
                cout << (char)('a'+i);
                break;
            }
        }
        cout << endl;
        return 0;
    }
    char mx = S.back();
    for(int i = S.size()-1; i >= 0; i--) {
        if(S[i] >= mx) {
            mx = max(mx,S[i]);
            continue;
        }
        else {
            for(int j = 0; j < i; j++) {
                cout << S[j];
            }
            char mi = mx;
            for(int j = i+1; j < S.size(); j++) {
                if(S[i] < S[j]) {
                    mi = min(mi,S[j]);
                }
            }
            cout << mi << endl;
            break;
        }
    }
}
