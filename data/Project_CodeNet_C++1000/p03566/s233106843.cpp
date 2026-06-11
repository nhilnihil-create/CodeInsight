#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<double> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

int main(){
    int N; scanf("%d",&N);
    vec t(N),v(N),sup(N);
    rep(i,N){
        scanf("%lf",&t[i]);
    }
    rep(i,N){
        scanf("%lf",&v[i]);
    }
    sup[N-1]=0.0;
    rep(i,N-1){
        sup[N-i-2]=min(v[N-i-2],min(sup[N-i-1]+t[N-i-1],v[N-i-1]));
    }
    double ans=0.0,V=0.0,T;
    rep(i,N){
        if(V+t[i]<sup[i]){
            ans+=t[i]*(t[i]+2.0*V)/2.0;
            V+=t[i];
        }
        else if(sup[i]==v[i]){
            T=v[i]-V;
            ans+=T*(V+v[i])/2.0+v[i]*(t[i]-T);
            V=v[i];
        }
        else{
            T=(t[i]+sup[i]-V)/2.0;
            if(V+T<v[i]){
                ans+=T*(T+2.0*V)/2.0+(t[i]-T)*(V+T+sup[i])/2.0;
                V=sup[i];
            }
            else{
                double T1=v[i]-V,T3=v[i]-sup[i],T2=t[i]-T1-T3;
                ans+=T1*(V+v[i])/2.0+T2*v[i]+T3*(v[i]+sup[i])/2.0;
                V=sup[i];
            }
        }
    }
    printf("%.10lf\n",ans);
    return 0;
}