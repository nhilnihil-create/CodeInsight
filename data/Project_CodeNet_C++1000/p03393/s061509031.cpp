#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    string S;
    cin >> S;

    if (S.size() < 26) {
        vector<bool> used(26);
        for (char &c : S) {
            used[c - 'a'] = true;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (!used[c - 'a']) {
                S.push_back(c);
                break;
            }
        }
        cout << S << endl;
    } else {
        if (S == "zyxwvutsrqponmlkjihgfedcba") {
            puts("-1");
            return 0;
        }
        
        int N = S.size();
        string T = S;
        set<char> st;
        repr(i, N) {
            st.insert(S[i]);
            T.pop_back();
            for (auto &c : st) {
                string res = T + c;
                if (S < res) {
                    cout << res << endl;
                    return 0;
                }
            }
        }
    }
}