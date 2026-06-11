#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int main()
{
    int R,C;
    cin >> R >> C;

    char c[R][C];
    int cnt=0;
    REP(i,R){
        REP(j,C){
            cin >> c[i][j];
            if('#' == c[i][j])cnt++;
        }
    }

    int dy[] = {-1,0,1,0};
    int dx[] = {0,-1,0,1};

    vector<vint> dist(R,vint(C,-1));
    queue<pair<int,int>> que;

    dist[0][0] = 0;
    que.push(make_pair(0,0));

    while(!que.empty()){
        auto p = que.front();
        que.pop();
        int y,x;
        y = p.first;
        x = p.second;

        REP(dir,4){
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if(ny < 0 || nx < 0 || ny > R-1 || nx > C - 1)continue;
            if('#' == c[ny][nx])continue;
            if(dist[ny][nx] != -1)continue;
            dist[ny][nx] = dist[y][x] + 1;
            que.push(make_pair(ny,nx));
        }
    }

    if(dist[R-1][C-1] != -1){
        cout << (R*C - cnt - dist[R-1][C-1] - 1) << endl;
    }else{
        cout << -1 << endl;
    }
}