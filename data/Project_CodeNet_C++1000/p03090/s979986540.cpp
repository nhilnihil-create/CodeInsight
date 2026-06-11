#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

const int maxn = 105;

vector<int> cc[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    if(n & 1){
        m = (n + 1) / 2;
        for(int i = 1;i <= n / 2;i++){
            cc[i].push_back(i);
            cc[i].push_back(n - i);
        }
        cc[m].push_back(n);
    }else{
        m = n / 2;
        for(int i = 1;i <= m;i++){
            cc[i].push_back(i);
            cc[i].push_back(n + 1 - i);
        }
    }
    vector<pi> edge;
    for(int i = 1;i < m;i++){
        for(int j = i + 1;j <= m;j++){
            for(auto u : cc[i]){
                for(auto v : cc[j]){
                    edge.eb(u, v);
                }
            }
        }
    }
    cout << edge.size() << endl;
    for(auto e : edge){
        cout << e.fi << " " << e.se << endl;
    }
    return 0;
}
