//------------------------------------------
// C++ templete 
//------------------------------------------
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<PII> VP;

//REPEAT
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//container util
//------------------------------------------
#define pb push_back
#define paired make_pair
#define ALL(a) (a).begin(),(a).end()
#define PRINT(V) for (auto v : (V)) cout << v << " "
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())

//constant
//------------------------------------------
const int MOD = 1000000007;
const int INF = 1061109567;
const double EPS = 1e-10;
const double PI  = acos(-1.0);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

//math
//------------------------------------------
int QP(int a,int b){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int QP(int a,int b,int MOD){int ans=1;do{if(b&1)ans=1ll*ans*a%MOD;a=1ll*a*a%MOD;}while(b>>=1);return ans;}
int GCD(int a,int b){return b?GCD(b,a%b):a;}

//debug
//------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

//grobal variable
//------------------------------------------
int N,M;
VI Vec;

//動的計画法で役に立つ関数
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int N, K; cin>>N>>K;

    cout << N-K+1<<endl;
  
    return 0;
}

