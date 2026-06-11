#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<int>cntS[26];
vector<int>cntT[26];
signed main() {
    string S,T;
    cin >> S >> T;
    for(int i = 0; i < S.size(); i++) {
        cntS[S[i]-'a'].push_back(i);
        cntT[T[i]-'a'].push_back(i);
    }
    bool ok = true;
    for(int i = 0; i < 26; i++) {
        if(cntS[i].size() == 0) {
            continue;
        }
        if(cntS[i].size() != cntT[T[cntS[i][0]]-'a'].size()) {
            ok = false;
        }
        else {
            for(int j = 0; j < cntS[i].size(); j++) {
                if(cntS[i][j] != cntT[T[cntS[i][0]]-'a'][j]) {
                    ok = false;
                }
            }
        }
    }
    if(ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
