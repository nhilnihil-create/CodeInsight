#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,n) for(int i=1;i<=(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define INF (1<<29)
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
const int MAX =510000;

ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
    ll g;g=gcd(a,b);
    return a*b/g;
}
const int N_max=51;
const int M_max=N_max*(N_max-1);
vector<int> v[51];
bool isVisited[N_max];
void initialize(){
    REP(i,N_max){
        isVisited[i]=false;
    }
}
void dfs(int v_now){
    isVisited[v_now]=true;
    for(int i:v[v_now]){
        if(!isVisited[i]){
            dfs(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S_ori=in<string>();
    REP(i,16){
        string S;S="";
        if((1&i>>0)==1){
            S.push_back('A');
        }
        S.push_back('K');
        S.push_back('I');
        S.push_back('H');
        if((1&i>>1)==1){
            S.push_back('A');
        }
        S.push_back('B');
        if((1&i>>2)==1){
            S.push_back('A');
        }
        S.push_back('R');
        if((1&i>>3)==1){
            S.push_back('A');
        }
        if(S_ori==S){
            print("YES");
            return 0;
        }
    }
    print("NO");
    return 0;
}