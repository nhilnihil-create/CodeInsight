#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef vector<int> vec;
typedef vector<int64> vec64;
#define db(x) cout << "> " << #x << ": " << x << "\n";
#define ss cout << " ";
#define ct(x) cout << x;
#define nn cout << "\n";
#define cts(x) cout << x << " ";
#define ctn(x) cout << x << "\n";
#define qr queries();
void solve();
void YN(bool b){if (b){ctn("YES");}else{ctn ("NO");}};
void yn(bool b){if (b){ctn("Yes");}else{ctn ("No");}};
void queries(){int n;cin >> n;while (n--)solve();}
// // // // // // // // // // // // // // // // // // // // // // 
/*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // //
int64 q, n;
const int MAXN = 200200;
vector <pair <int, int> > ad [MAXN];
vector <int64> cost (MAXN);
vector <bool> rs (MAXN);
vector <bool> visited (MAXN);
map <pair <int, int>, int > mp;
void solve(){

    return;
}

void dfs (int n){
    // ctn(n);
    if (!visited[n]){
        visited[n] = 1;
        for (int i = 0; i < ad[n].size(); i++){
            int cur = ad[n][i].first;
            int c = ad[n][i].second;
            if (!visited[cur]){
                cost[cur] = cost[n] + c;
                dfs(cur);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++){
        int x,y,z;
        cin >> x >> y >> z;
        ad[x].push_back({y,z});
        ad[y].push_back({x,z});
    }
    dfs(1);
    for (int i = 1; i <= n; i++){
        // db(cost[i]);
        if (cost[i] % 2 == 0){
            ctn(0);
        }
        else{
            ctn(1);
        }
    }
    return 0;
}
