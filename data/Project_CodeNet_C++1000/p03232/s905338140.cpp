#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<utility>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
typedef long long int ll;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<signed(n);i++)
#define EREP(i,n) for(int i=1;i<=signed(n);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
//#define EVEL 1
#ifdef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
constexpr int MOD = 1000000007;
constexpr ll INF = 50000000000000000;
typedef std::pair<int,int> P;
constexpr ll SIZE= 100010;

ll Fact[SIZE];
ll Com[SIZE];
ll LP(ll x,ll y);
void FC(ll x);
ll MC(ll x,ll y);
ll LP(ll x,ll y){
    if(y==0)return 1;
    if(y%2==0)return LP((x*x)%MOD,y/2)%MOD;
    else return LP(x,y-1)*x%MOD;
}
void FC(ll x){
    Fact[0]=Com[0]=1;
    ll temp=1;
    EREP(i,x){
        //temp=temp*i%MOD;
        temp=(temp*(ll)i)%MOD;
        Fact[i]=temp;
        //Com[i]=LP(temp,MOD-2);
        Com[i]=LP(i,MOD-2);
    }
}
ll MC(ll x,ll y){
    if(y==0)return 1;
    if(x<y)return 0;
    return (Fact[x]*(Com[y]*Com[x-y]%MOD))%MOD;
}

ll N,M;
ll S[100010];
ll ans=0;
bool F=true;
int main() {
    std::ios_base::sync_with_stdio(false);
    cin>>N;
    FC(N);
    S[0]=Com[1];
    //ComとFactは1-indexed
    REP(i,N){
        S[i+1]+=S[i]+Com[i+2];
        S[i+1]%=MOD;
    }
    REP(i,N){
        ll a;
        cin>>a;
            ll s=S[N-1-i];
            s+=S[i]-S[0];
        s%=MOD;ans+=s*a%MOD;ans%=MOD;
    }
    cout<<(ans*Fact[N])%MOD<<endl;
    return 0;
}
