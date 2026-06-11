#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> Pa;
int INF = 1e16+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>P(N);
    map<int,int>Mp;
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        if(Mp.count(P[i]-1)) {
            Mp[P[i]] = Mp[P[i]-1]+1;
        }
        else {
            Mp[P[i]] = 1;
        }
    }
    int cnt = 0;
    for(Pa x:Mp) {
        cnt = max(cnt,x.second);
    }
    cout << N-cnt << endl;
}
