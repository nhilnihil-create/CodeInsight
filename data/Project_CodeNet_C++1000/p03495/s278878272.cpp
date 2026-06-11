#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N,K,a,ans = 0;
    cin >> N >> K;

    map<int64_t,int> mp;
    for(int i=0;i<N;i++) {
        cin >> a;
        mp[a]++;
    }
    vector<int> ball(mp.size());
    a = 0;
    for(auto m:mp) {
        ball[a] =m.second;
        a++;
    }

    sort(ball.begin(), ball.end());
    for(int i=K;i<ball.size();i++) {
        ans += ball[i-K];
    }

    cout << ans << endl;
    return 0;
}
