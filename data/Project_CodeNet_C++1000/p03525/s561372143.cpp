#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>D(N);
    vector<int>cnt(13);
    for(int i = 0; i < N; i++) {
        cin >> D[i];
        cnt[D[i]]++;
    }
    int ans = 0;
    int sum = INF;
    vector<int>cnt2;
    vector<int>cnt3;
    cnt[0]++;
    for(int i = 0; i <= 12; i++) {
        if(cnt[i] == 1) {
            cnt2.push_back(i);
        }
        if(cnt[i] >= 2) {
            sum = min(sum,min(abs((24-i)-i),24-abs((24-i)-i)));
            cnt3.push_back(i);
            cnt3.push_back(24-i);
        }
        if(cnt[i] >= 3) {
            cout << 0 << endl;
            return 0;
        }
    }
    int n = cnt2.size();
    for(int i = 0; i < (1 << n); i++) {
        int res = INF;
        vector<int>res2(n,0);
        for(int j = 0; j < n; j++) {
            if(1 & (i >> j)) {
                res2[j] = cnt2[j];
            }
            else {
                res2[j] = 24-cnt2[j];
            }
        }
        for(int j = 0; j < n; j++) {
            for(int k = j+1; k < n; k++) {
                res = min(res,min(abs(res2[j]-res2[k]),24-abs(res2[j]-res2[k])));
            }
        }
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < cnt3.size(); k++) {
                res = min(res,min(abs(res2[j]-cnt3[k]),24-abs(res2[j]-cnt3[k])));
            }
        }
        if(sum != INF) {
            res = min(res,sum);
        }
        ans = max(ans,res);
    }
    cout << ans << endl;
}
