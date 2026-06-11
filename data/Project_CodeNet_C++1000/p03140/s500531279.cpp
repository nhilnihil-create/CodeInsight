#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    string s[3];
    REP(i,3){
        cin >> s[i];
    }
    int ans = 0;
    REP(i,n){
        int cnt[26] = {};
        REP(j,3){
            cnt[s[j][i] - 'a']++;
        }
        sort(cnt, cnt + 26);
        reverse(cnt, cnt + 26);
        ans += 3 - cnt[0];
    }
    cout << ans << endl;
}