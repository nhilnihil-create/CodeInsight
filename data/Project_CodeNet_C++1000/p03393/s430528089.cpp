#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main(){
    string S;
    cin >> S;
    if(S.size() != 26) {
        vector<int>cnt(26);
        for(int i = 0; i < S.size(); i++) {
            cnt[S[i]-'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] == 0) {
                cout << S << (char)(i+'a') << endl;
                return 0;
            }
        }
    }
    else {
        if(S == "zyxwvutsrqponmlkjihgfedcba") {
            cout << -1 << endl;
            return 0;
        }
        char c = S[25];
        string T = "";
        T+=c;
        for(int i = 24; i >= 0; i--) {
            if(S[i] < c) {
                cout << S.substr(0,i);
                for(int j = 0; j < T.size(); j++) {
                    if(S[i] < T[j]) {
                        c = min(c,T[j]);
                    }
                }
                cout << c << endl;
                return 0;
            }
            else {
                c = max(c,S[i]);
                T+=S[i];
            }
        }
    }
}