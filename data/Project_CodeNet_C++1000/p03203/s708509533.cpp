#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

int n, m;
int k;

const int maxn = 2e5 + 5;
vector<int> G[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> k; 
    for(int i = 1;i <= k;i++){
        int x, y;
        cin >> x >> y;
        G[y].push_back(x);
    }
    int cnt = 0;
    int ans = 1e9;
    for(int i = 1;i <= m;i++){
        sort(G[i].begin(), G[i].end());
        int val = n + 1;
        for(auto v : G[i]){
            if(v < cnt + i){
                continue;
            }else if(v == cnt + i){
                cnt++;
            }else{
                val = v;
                break;
            }
        }
        ans = min(ans, val - 1);
    }
    cout << ans << endl;
    return 0;
}
