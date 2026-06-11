#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define INF 1LL << 55
#define MAX (1LL << 31) -1
#define MOD 1000000007
typedef long long ll;
typedef pair<int,ll> P;
typedef pair<pair<int,int>,ll> p;
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll
int dx[]={1,-1,0,0},dy[]={0,0,-1,1};
//#define F function<T(T,T)>

int N,Q;
string S;
vector<char> t,d;

bool checkR(int x){
    for(int i=0;i<Q;i++){
        if(S[x]==t[i]){
            if(d[i]=='L') x--;
            else x++;
        }
        if(x==-1) return false;
        if(x==N) return true;
    }
    return false;
}

bool checkL(int x){
    for(int i=0;i<Q;i++){
        if(S[x]==t[i]){
            if(d[i]=='L') x--;
            else x++;
        }
        if(x==-1) return true;
        if(x==N) return false;
    }
    return false;
}


signed main(){
    
    cin>>N>>Q>>S;
    t.resize(Q);
    d.resize(Q);

    for(int i=0;i<Q;i++) cin>>t[i]>>d[i];
    int ok=N,ng=-1;
    while(ok-ng!=1){
        int mid=(ng+ok)/2;
        if(checkR(mid)) ok=mid;
        else ng=mid;
    }
    int r=ok;
    ok=-1,ng=N;
    while(ng-ok!=1){
        int mid=(ng+ok)/2;
        if(checkL(mid)) ok=mid;
        else ng=mid;
    }
    int l=ok;
    if(l>=r) cout<<N<<endl;
    else cout<<N-( (N-1-r+1)+(l+1) )<<endl;
}