#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<vector<int>>v;
vector<int> temp;
int n, m, k[12], p[12], s[12][12], ans = 0;
void solve(int idx){
    if(idx >= n){
        v.push_back(temp);
        return;
    }
    temp[idx] = 1;
    solve(idx + 1);
    temp[idx] = 0;
    solve(idx + 1);
}
int main(){
    Hello
    cin >> n >> m;
    for(int i = 0; i < n; i++) temp.push_back(0);
    for(int i = 0; i < m; i++){
        cin >> k[i];
        for(int j = 0; j < k[i]; j++){
            cin >> s[i][j];
            s[i][j]--;
        }
    }
    for(int i = 0; i < m; i++) cin >> p[i];
    solve(0);
    for(int cur = 0; cur < v.size(); cur++){
        int allbulbs = 0;
        for(int i = 0; i < m; i++){
            int lighted = 0;
            for(int j = 0; j < k[i]; j++){
                if(v[cur][s[i][j]])
                    lighted++;
            }
            if(lighted % 2 == p[i] % 2)
                allbulbs++;
        }
        if(allbulbs == m)
            ans++;
    }
    cout << ans;
    return 0;
}
