#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    string S;
    cin >> N >> S;
    int ans = 0;
    for(int i = 1; i < N; i++) {
        int cnt = 0;
        string s = "";
        string t = "";
        for(int j = 0; j < i; j++) {
            s+=S[j];
        }
        for(int j = i; j < N; j++) {
            t+=S[j];
        }
        vector<int>hantei(26);
        for(int j = 0; j < s.size(); j++) {
            hantei[s[j]-'a']++;
        }
        vector<bool>ok(26,false);
        for(int j = 0; j < t.size();  j++) {
            if(hantei[t[j]-'a']){
                ok[t[j]-'a'] = true;
            }
        }
        for(int j = 0; j < 26; j++) {
            if(ok[j]) {
                cnt++;
            }
        }
        ans = max(ans,cnt);
    }
    cout << ans << endl;
}
