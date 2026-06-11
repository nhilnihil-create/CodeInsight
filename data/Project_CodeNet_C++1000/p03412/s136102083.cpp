#include <bits/stdc++.h>
#define ll long long
double EPS = 1e-9;
constexpr ll MOD =  1e9+9;
using namespace std;
vector<int> node[2][29];

int main()
{
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    int res = 0;
    for(int i = 0;i < n;i++){
        cin >> b[i];
        res ^= b[i];
    }
//    cout << res << endl;
    for(int i = 0;i < 29;i++)
        for(int j = 0;j < n;j++){
            node[(b[j]&(1<<i)) ? 1 : 0][i].push_back(((1 << i) - 1) & b[j]);
        }
    for(int i = 0;i < 29;i++){
        sort(node[0][i].begin(), node[0][i].end());
        sort(node[1][i].begin(), node[1][i].end());
    }

    int bts[29] = {0};
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 29;j++){
            if(j == 0){
                if(a[i] & 1){
                    bts[0] ^= (node[0][0].size())&1;
                }else{
                    bts[0] ^= (node[1][0].size())&1;
                }
                continue;
            }

            if(a[i]&(1<<j)){
                auto it = lower_bound(node[0][j].begin(), node[0][j].end(), (1<<j) - (((1<<j)-1) & a[i]));
                bts[j] ^= (it - node[0][j].begin())&1;
                it = lower_bound(node[1][j].begin(), node[1][j].end(), (1<<j) - (((1<<j)-1) & a[i]));
                bts[j] ^= (node[1][j].end() - it)&1;
            }else{
                auto it = lower_bound(node[0][j].begin(), node[0][j].end(), (1<<j) - (((1<<j)-1) & a[i]));
                bts[j] ^= (node[0][j].end() - it)&1;
                it = lower_bound(node[1][j].begin(), node[1][j].end(), (1<<j) - (((1<<j)-1) & a[i]));
                bts[j] ^= (it - node[1][j].begin())&1;
            }
        }
    }
    ll ans = 0;
    for(int i = 0;i < 29;i++){
        ans |= (bts[i] << i);
    }
    cout << ans;
    return 0;
}
