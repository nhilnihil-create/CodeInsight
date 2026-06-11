#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e16+7;
int mod = 1e9+7;
int dx[4] = {1,-1, 0, 0};
int dy[4] = {0, 0, 1,-1};
signed main() {
    int N;
    cin >> N;
    vector<int>b(N);
    for(int i = 0; i < N; i++) {
        cin >> b[i];
    }
    vector<int>ans;
    while(N--) {
        for(int i = b.size()-1; i >= 0; i--) {
            if(b[i] == i+1) {
                ans.push_back(b[i]);
                b.erase(b.begin()+i);
                goto home;
            }
        }
        cout << -1 << endl;
        return 0;
    home:;
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
