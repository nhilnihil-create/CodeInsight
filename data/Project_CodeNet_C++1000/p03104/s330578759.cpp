#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> P;
typedef priority_queue<P,vector<P>,greater<P>> P_queue;

#define REP(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define SORT(a) sort(ALL(a))
#define U_ERASE(V) V.erase(unique(ALL(V)), V.end());

const ll MOD=998244353;
const ll mod=1000000007;
const ll INF=1e15;
vec dx={1,0,-1,0};
vec dy={0,1,0,-1};

ll SUM(ll A){
    if(A<=1) return A;
    ll count=2;
    ll ret=0;
    if(A%4==2 || A%4==1) ret=1;
    A++;
    
    while(count<A){
        ll x=A/count;
        ll y=A%count;
        if(x%2 && y%2) ret+=count;
        count*=2;
    }
    return ret;
}

int main(){
    ll A,B; cin>>A>>B;
    if(A>B) swap(A,B);
    if(A==0) cout<<SUM(B)<<endl;
    else cout<<(SUM(A-1)^SUM(B))<<endl;
    //cout<<SUM(A-1)<<':'<<SUM(B)<<endl;
}