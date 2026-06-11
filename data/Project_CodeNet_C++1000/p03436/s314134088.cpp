#include<bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0, i##_len=(n); i<i##_len; ++i)
typedef long long ll;
#define pb push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p){os<<"("<<p.first<<","<< p.second<<")";return os;}
template <class T> ostream &operator<<(ostream &os, const vector<T> &v){os<<"{";REP(i,(int)v.size()){if(i)os<<",";os<<v[i];}os<<"}";return os;}
template <typename T, size_t S> void printArray(const T (&array)[S]){for(auto val : array)std::cout << val << ", ";std::cout << "\n";}
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
const double PI=acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;
template<class T>inline bool chmax(T& a, T b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T& a, T b){if(a > b){a = b; return 1;}return 0;}
const ll INF = 1LL<<60;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
//const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
//const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

queue<pair<ll, ll>> que;
ll h, w; 

void bfs(vector<string>& vs, vector<vector<ll>>& seen){
    ll nowy, nowx;
    if(!que.empty()){
        nowy = que.front().fi, nowx =que.front().se;
        que.pop();
    }
    else{
        cout << -1 << endl;
        exit(0);
    }
    if(nowy == h-1 && nowx == w-1){
        return;
    }
    ll ncnt = seen[nowy][nowx];
    for(int i=0; i<4; i++){
        ll nxty = nowy + dy[i], nxtx = nowx + dx[i];
        //cout << seen << endl;

        if(nxty >= 0 && nxty < h && nxtx >= 0 && nxtx < w){
            //cout << nxty << ' ' << nxtx << 'z' << endl;
            if(vs[nxty][nxtx] == '.' && seen[nxty][nxtx] == -1){
                seen[nxty][nxtx] = ncnt+1;
                //else seen[nxty][nxtx] = min(ncnt+1, seen[nxty][nxtx]);
                que.push({nxty, nxtx});
            }
        }
    }
    bfs(vs, seen); 
}

void solve(){
    cin >> h >> w;
    vector<string> vs;
    REP(i, h){
        string s; cin >> s;
        vs.pb(s);
    }
    ll bcnt = 0;
    REP(i, h){
        REP(j, w){
            if(vs[i][j] == '#') bcnt++;
        }
    }
    vector<vector<ll>> seen(h, vector<ll>(w, -1));
    que.push({0, 0});
    seen[0][0] = 1;
    bfs(vs, seen);
    ll saitan = seen[h-1][w-1];
    cout << h*w - saitan - bcnt << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
}