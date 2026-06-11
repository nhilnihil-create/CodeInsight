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

char field[55][55];
int w,h;
int dx[8] = {1,1,0,-1,-1,-1,0,1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

void dfs(int x, int y){
    field[x][y] = '0';
    rep(t,0,8){
        int nx = x + dx[t];
        int ny = y + dy[t];
        if(nx >= 0 && nx < h && ny >= 0 && ny < w){
            dfs(nx,ny);
        }
    }
}


int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    pair<int,int> p[100100];
    rep(i,0,m){
        int a,b; cin >> a >> b;
        p[i] = mp(b,a);
    }
    sort(p,p+m);
    int left = 1;
    int ans = 0;
    rep(i,0,m){
        if(p[i].second >= left){
            ans++;
            left = p[i].first;
        }
    }
    cout << ans << endl;
    return 0;
}