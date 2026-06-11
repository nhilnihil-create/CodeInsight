#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
using namespace std;
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-10;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)


//ここから編集
int H, W, N;
int sy, sx; 
string s, t; 
int solve(){

    int left = 0, right = W;
    if(s[N-1] == 'L') left++;
    if(s[N-1] == 'R') right--;

    for(int i=N-2; i>=0; i--){
        if(t[i] == 'L') right = min(right+1, W);
        else if(t[i] == 'R') left = max(left-1, 0);
        if(s[i] == 'L') left = left+1;
        else if(s[i] == 'R') right = right-1;
        if(left >= right) return 0;
    }
    if(sx < left || sx >= right) return 0;

    left = 0, right = H;
    if(s[N-1] == 'U') left++;
    if(s[N-1] == 'D') right--;

    for(int i=N-2; i>=0; i--){
        if(t[i] == 'U') right = min(right+1, H);
        else if(t[i] == 'D') left = max(left-1, 0);
        if(s[i] == 'U') left = left+1;
        else if(s[i] == 'D') right = right-1;
        if(left >= right) return 0;
    }
    if(sy < left || sy >= right) return 0;

    return 1;

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    
    
    cin >> H >> W >> N;
    cin >> sy >> sx;
    sy--; sx--;
    cin >> s >> t;

    if(!solve()) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}
