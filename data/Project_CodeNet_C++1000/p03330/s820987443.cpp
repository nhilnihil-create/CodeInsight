#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
int n, c;

vector<vector<int> > color;
void dfs(int idx, vector<int> tmp, int now){
    if(idx == 2) color.push_back(tmp);
    else {
        for(int i = now+1;i<=c-1;i++){
            tmp.push_back(i);
            dfs(idx+1, tmp, i);
            tmp.pop_back();
        }
    }
}
 
int main(void){
    cin>>n>>c;
    vector<vector<int> > d(c, vector<int>(c));
    rep(i, c)rep(j, c) cin>>d[i][j];
    vector<vector<int> > v(n, vector<int>(n));
    rep(i, n)rep(j, n) {
        int a;
        cin>>a;
        --a;
        v[i][j] =a;
    }
    vector<unordered_map<int, int> > vmap(3);
    rep(i, n)rep(j, n){
        vmap[(i+j)%3][v[i][j]]++;
    }
    vector<int>tmp;
    dfs(-1, tmp, -1);
    int ans = INF;
    rep(i, color.size()){
        do{
            int tmp = 0;
            rep(j, 3) {
                for(auto p : vmap[j]){
                    tmp += p.second*d[p.first][color[i][j]];
                }
            }
            ans = min(ans, tmp);
        }while(next_permutation(color[i].begin(), color[i].end()));
    }
    cout<<ans<<endl;
    return 0;
}