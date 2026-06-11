#include <bits/stdc++.h>

using namespace std;


//repetition
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define euc_dis(x, y) sqrt(x*x + y*y)

#define pb push_back
#define INF 999999999
#define MOD 1000000007
#define sp ' '


//typedef
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<long, long> pll;
typedef map<int, int> mint;
typedef set<int> sint;
typedef vector<int> vint;
typedef vector<char> vchr;
typedef vector<long long> vll;
typedef vector<string> vstr;


ll mod(ll a, ll b){return (a%b+b)%b;}
ll gcd(ll a, ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){return a*b/gcd(a,b);}
void Yes(){cout << "Yes" << endl;}
void No(){cout << "No" << endl;}
void Judge(bool b){b?Yes():No();}
void YES(){cout << "YES" << endl;}
void NO(){cout << "NO" << endl;}
void JUDGE(bool b){b?YES():NO();}
ll powMod(ll a, ll b, ll c){ll ans=1; rep(i, b){ans=ans*a%c;} return ans;}
double distance(ll x1, ll y1, ll x2, ll y2){return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));}

template<typename T>
void ppp(T n){cout << n << endl;}
template<typename T>
void dpp(T n){cerr << n << endl;}
template<typename T>
void vpp(T a){rep(i,a.size()){cout << a[i] << endl;}}
template<typename T>
void vdp(T a){rep(i,a.size()){cerr << a[i];}cerr << endl;}

const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
const int ddx[8] = {1,0,-1,0,1,-1,-1,1};
const int ddy[8] = {0,1,0,-1,1,1,-1,-1};


const int nmax = 50;

int n, m;
int a[101], b[101];

bool graph[101][101];
bool visited[101];

void dfs(int v){
    visited[v] = true;
    for(int w = 0; w < n; ++w){
        if(!graph[v][w]) continue;
        if(visited[w]) continue;
        dfs(w);
    }

}


int main(){
    int ans = 0;

    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
    }

    for(int i = 0; i < m; ++i){

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

        for(int j = 0; j < n; ++j){
            visited[j] = false;
        }

        dfs(1);

        bool bridge = false;
        for(int j = 0; j < n; ++j){
            if(!visited[j]) bridge = true;
        }

        if(bridge) ++ans;

        graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;

    }

    ppp(ans);

    return 0;
}
