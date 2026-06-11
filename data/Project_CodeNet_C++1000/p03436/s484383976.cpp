#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<stack>
#include<set>
#include<map>
#include<bitset>
#include<string>
#define rep(i,n,m) for(int i=(n);i<(int)(m);i++)
#define reps(i,n,m) for(int i=(n);i<=(int)(m);i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define lb lower_bound
#define ub upper_bound
#define LB(a,x) lb(all(a), x) - a.begin()
#define UB(a,x) ub(all(a), x) - a.begin()
#define printfdouble(x) printf("%.12f\n",(x))
#define chartoint(c) (int)((c) - '0')
#define chartoll(c) (long long)((c) - '0')
#define MOD 1000000007
#define itn int
#define enld endl
#define ednl endl
#define icn cin
#define stirng string
using namespace std;
typedef long long ll;
const double pi = 3.141592653589793;
using Graph = vector<vector<int>>;
template<class T> bool chmax(T &a, const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b){if(b<a){a=b; return 1;} return 0;}
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int H,W; cin >> H >> W;
    char field[55][55];
    int dist[55][55];
    Fill(dist, -1);
    dist[0][0] = 0;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};

    int cnt = 0;
    rep(i,0,H){
        rep(j,0,W){
            cin >> field[i][j];
            if(field[i][j] == '.'){
                if(i == 0 && j == 0) continue;
                cnt++;
            }
        }
    }
    
    queue<pair<int,int>> que;
    que.push({0,0});

    while(!que.empty()){
        auto v = que.front();
        que.pop();
        rep(t,0,4){
            int nx = v.first + dx[t];
            int ny = v.second + dy[t];
            if(nx >= 0 && nx < H && ny >= 0 && ny < W && field[nx][ny] == '.' && dist[nx][ny] == -1){
                que.push({nx,ny});
                dist[nx][ny] = dist[v.first][v.second] + 1;
            }
        }
    }
    if(dist[H-1][W-1] == -1){
        cout << -1 << endl;
    }else{
        cout << cnt - dist[H-1][W-1] << endl;
    }
}