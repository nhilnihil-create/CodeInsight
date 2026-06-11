#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N,K;
    cin >> N >> K;
    vector<int>a(N);
    vector<int>s(N+1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        s[i+1] = s[i]+a[i];
    }
    vector<int>res;
    for(int i = 0; i <= N; i++) {
        for(int j = i; j <= N; j++) {
            res.push_back(s[j]-s[i]);
        }
    }
    vector<vector<int>>cnt(res.size(),vector<int>(50));
    for(int i = 0; i < res.size(); i++) {
        int X = res[i];
        int time = 0;
        while (time < 50) {
            cnt[i][time++] = X%2;
            X >>= 1;
        }
    }
    int ans = 0;
    set<int>st;
    for(int i = 0; i < res.size(); i++) {
        st.insert(i);
    }
    for(int i = 49; i >= 0; i--) {
        int sum = 0;
        for(int x:st) {
            if(cnt[x][i]) {
                sum++;
            }
        }
        if(sum >= K) {
            ans += pow(2,i);
            auto it = st.begin();
            while (it != st.end()) {
                if(cnt[*it][i] == 0) {
                    st.erase(it++);
                }
                else {
                    it++;
                }
            }
        }
    }
    cout << ans << endl;
}
