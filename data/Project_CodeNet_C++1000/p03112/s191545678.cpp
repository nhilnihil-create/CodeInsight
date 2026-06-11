#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int A,B,Q;
    cin >> A >> B >> Q;
    vector<int>s(A+2);
    vector<int>t(B+2);
    for(int i = 1; i <= A; i++) {
        cin >> s[i];
    }
    for(int i = 1; i <= B; i++) {
        cin >> t[i];
    }
    s[0] = -INF;t[0] = -INF;
    s[A+1] = INF;t[B+1] = INF;
    for(int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        auto it1 = lower_bound(s.begin(),s.end(),x);
        auto it2 = lower_bound(t.begin(),t.end(),x);
        auto it3 = it1-1;
        auto it4 = it2-1;
        int ans = INF;
        ans = min(ans,max(s[it1-s.begin()],t[it2-t.begin()])-x);
        ans = min(ans,x-min(s[it3-s.begin()],t[it4-t.begin()]));
        ans = min(ans,min(x-s[it3-s.begin()]+t[it2-t.begin()]-s[it3-s.begin()],t[it2-t.begin()]-x+t[it2-t.begin()]-s[it3-s.begin()]));
        ans = min(ans,min(x-t[it4-t.begin()]+s[it1-s.begin()]-t[it4-t.begin()],s[it1-s.begin()]-x+s[it1-s.begin()]-t[it4-t.begin()]));
        cout << ans << endl;
    }
}