#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> ob;
    for (int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;
        ob.push_back({X, Y});
    }
    sort(ob.begin(), ob.end());
    int t = 0;
    for (int i = 0; i < N; i++) {
        int X, Y;
        X = ob[i].first;
        Y = ob[i].second;
        if (X-Y < t)continue;
        else if (X-Y == t) t++;
        else if (X-Y > t) {
            cout << X-1 << endl;
            return 0;
        }
    }
    cout << H << endl;
    return 0;
}
