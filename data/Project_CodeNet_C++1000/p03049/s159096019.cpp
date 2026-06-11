#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define ALL(a)  (a).begin(),(a).end()
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=max(x,a)
#define chmin(x,a) x=min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
const int MOD = 1000000007;
#define INF 1<<30
#define INFTY 1LL<<61
#define MAX_INT INT_MAX
#define Endl '\n'
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
template<class T> bool contain(const std::string& s, const T& v) {
   return s.find(v) != std::string::npos;
}
using Edge=pair<int,ll>;
using Graph=vector<vector<int> >;//ll or Edge
using Edge=pair<int,ll>;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
// sort_reverse...greater<ll>()
// vector型から重複を削除 list.erase(unique(ALL(list)),list.end());
// g++ -o a a.cpp -Wall -lm -std=c++17
int main(){
    int n;cin>>n;
    vector<string>S(n);
    rep(i,n)cin>>S[i];
    ll ans=0;
    ll ABnum=0,Anum=0,Bnum=0;

    rep(i,n){
        int l=(int)S[i].size();
        for(int j=0;j<(int)S[i].size()-1;j++){
            if(S[i][j]=='A' && S[i][j+1]=='B')ans++;
        }
        if(S[i][0]=='B' && S[i][l-1]=='A')ABnum++;
        else if(S[i][0]=='B')Bnum++;
        else if(S[i][l-1]=='A')Anum++;
    }
    if(ABnum==0)ans+=min(Anum,Bnum);
    else if(Anum+Bnum>0)ans+=min(Anum,Bnum)+ABnum;
    else if(Anum+Bnum==0)ans+=min(Anum,Bnum)+ABnum-1;
    cout<<ans<<endl;
}