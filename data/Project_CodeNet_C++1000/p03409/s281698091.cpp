#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rep2(i,s,n) for (int i = s; i < n; ++i)
#define _GLIBCXX_DEBUG
using namespace std;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<P> red(n);
    vector<P> blue(n);
    rep(i,n) {
        int a,b;
        cin >> a >> b;
        red[i] = {a,b};
    }
    rep(i,n) {
        int c,d;
        cin >> c >> d;
        blue[i] = {c,d};
    }
    sort(blue.begin(),blue.end());
    auto judge = [&](P bl,P re) {
        return re.first < bl.first && re.second < bl.second;
    };
    int ans = 0;
    vector<bool> used(n,false);
    for(auto bl : blue) {
        int maxy = -1;
        int now;
        rep(i,n) {
            if(used[i]) continue;
            if(judge(bl,red[i])) {
                if(red[i].second > maxy) {
                    now = i;
                    maxy = red[i].second;
                }
            }
        }
        if(maxy != -1) {
            used[now] = true;
            ans++;
        }
    }
    cout << ans << endl;
}