#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    int N, x;
    cin >> N >> x;
    vector<int> kids(N);
    rep(i, N){
        cin >> kids.at(i);
    }
    sort(kids.begin(), kids.end());
    int ans = 0;
    bool complete = true;
    for(int kid : kids){
        if(x >= kid){
            x -= kid;
            ans++;
        } else {
            complete = false;
            break;
        }
    }
    if(x > 0 && ans > 0 && complete) ans--;
    cout << ans << endl;
}