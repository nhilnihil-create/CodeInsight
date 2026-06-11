#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int main(){
    int h, w, counter=0;
    cin >> h >> w;
    int check=h*w;
    int s[h][w];
    queue<pair<int,int>> que;
    rep(i,h){
        rep(j,w){
            char x;
            cin >> x;
            if(x=='#'){
                s[i][j]=1;
                que.push({i,j});
                ++counter;
                --check;
            }else if(x=='.'){
                s[i][j]=2;
            }
        }
    }
    int counter1=0, ans=0;
    if(check==0){
        cout << 0 << "\n";
        return 0;
    }
    while(!que.empty()) {
        if(counter==0){
            counter=counter1;
            ++ans;
            if(check==0){
                cout << ans << "\n";
                return 0;
            }
            counter1=0;
        }
        int u=que.front().first, v=que.front().second;
        que.pop();
        --counter;
        rep(i,4) {
            if(u+dy[i]<0 || v+dx[i]<0 || u+dy[i]>=h || v+dx[i]>=w) continue;
            if(s[u][v]==1 && s[u+dy[i]][v+dx[i]]==2) {
                s[u+dy[i]][v+dx[i]] = 1;
                --check;
                que.push({u+dy[i],v+dx[i]});
                ++counter1;
            }
        }
    }
    return 0;
}