#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int main(){
    int h, w, n, ans = 1000000000;
    cin >> h >> w >> n;
    vector<set<int>> st(w + 2);
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        st[y].insert(x);
    }
    for(int i = 1; i <= w; i++){
        st[i].insert(h + 1);
    }
    int cnt = 0;
    for(int i = 1; i <= w; i++){
        if(i + cnt > h) break;
        ans = min(ans, *st[i].upper_bound(i + cnt) - 1);
        for(auto&& j : st[i + 1]){
            if(i + cnt + 1 > j) continue;
            else if(i + cnt + 1 == j) cnt++;
            else break;
        }
    }
    cout << ans << endl;
    return 0;
}
