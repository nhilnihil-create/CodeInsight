#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

bool visited[2 * 100000 + 10];
unordered_map<int, int> mp;

//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w, n, x[2 * 100000 + 10], y[2 * 100000 + 10], ans, lim = 1;

    cin >> h >> w >> n;
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
        if(!visited[x[i]])mp[x[i]] = y[i], visited[x[i]] = true;
        else mp[x[i]] = min(mp[x[i]], y[i]);
    }

    ans = h;
    for(int i = 2; i <= h; i++){
        if(!visited[i])lim++;
        else{
            if(lim + 1 == mp[i])continue;
            else if(lim + 1 < mp[i])lim++;
            else{
                ans = i - 1;
                break;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
