#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int INF = 1e9;
 
int main(void){
    int h, w;
    cin>>h>>w;
    vector<string> v(h);
    rep(i, h) cin>>v[i];
    queue<pair<int, int> > que;
    queue<pair<int, int> > nextque;
    rep(i, h)rep(j, w)if(v[i][j] == '#') que.push(make_pair(i, j));
    int ans = 0;
    bool ok = true;
    vector<int>dx = {0, -1, 0, 1};
    vector<int>dy = {-1, 0, 1, 0};
    while(ok){
        nextque = queue<pair<int, int> >();
        while(!que.empty()){
            auto p = que.front();que.pop();
            rep(i, 4){
                if(p.first+dx[i]>=0 && p.first+dx[i]<=h-1 && p.second+dy[i]>=0 && p.second+dy[i]<=w-1 && v[p.first+dx[i]][p.second+dy[i]] == '.'){
                    v[p.first+dx[i]][p.second+dy[i]] = '#';
                    nextque.push(make_pair(p.first+dx[i], p.second+dy[i]));
                }
            }
        }
        ok = !nextque.empty();
        que = nextque;
        if(ok) ans++;
    }
    cout<<ans<<endl;
    return 0;
}