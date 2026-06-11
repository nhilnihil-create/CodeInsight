#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    map<int,int>mp;
    vector<int>D(N);
    for(int i = 0; i < N; i++) {
        cin >> D[i];
        mp[D[i]]++;
    }
    int M;
    cin >> M;
    for(int i = 0; i < M; i++) {
        int T;
        cin >> T;
        if(mp[T] <= 0) {
            cout << "NO" << endl;
            return 0;
        }
        mp[T]--;
    }
    cout << "YES" << endl;
}