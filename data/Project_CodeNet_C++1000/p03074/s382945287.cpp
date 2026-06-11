#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<pair<char,int>>cnt;
    cnt.push_back({'Z',-1});
    for(int i = 0; i < N; i++) {
        if(cnt.back().first == S[i]) {
            cnt.back().second++;
        }
        else {
            cnt.push_back({S[i],1});
        }
    }
    cnt.erase(cnt.begin());
    int l = 0,r = 0,sum = 0,ans = 0,now = 0;
    while(r < cnt.size()) {
        sum+=cnt[r].second;
        if(cnt[r].first == '0') {
            now++;
        }
        if(now > K) {
            if(cnt[l].first == '0') {
                sum-=cnt[l].second;
                l++;
            }
            else {
                sum-=cnt[l].second;
                sum-=cnt[l+1].second;
                l+=2;
            }
            now--;
        }
        ans = max(ans,sum);
        r++;
    }
    cout << ans << endl;
}
