#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0 , -1};
signed main() {
    int N;
    cin >> N;
    vector<pair<pair<string,int>,int>> vec(N);
    vector<int>ans(N);
    for(int i = 0; i < N; i++) {
        string S;
        int P;
        cin >> S >> P;
        vec[i].first.first = S;
        vec[i].first.second = -P;
        vec[i].second = i;
    }
    sort(vec.begin(),vec.end());
    for(int i = 0; i < N; i++) {
        cout << vec[i].second+1 << endl;
    }
}
