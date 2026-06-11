#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
//template end



int main(){
    int n,k; scanf("%d%d",&n,&k);
    vector<P> td(n);
    rep(i,0,n)scanf("%lld%lld",&td[i].second,&td[i].first);
    sort(ALL(td),greater<P>());
    ll sub=0,kind=0; bool used[100010]={};
    priority_queue<ll,vector<ll>,greater<ll>> pq;
    rep(i,0,k){
        sub+=td[i].first;
        if(used[td[i].second])pq.push(td[i].first);
        else used[td[i].second]=1,kind++;
    }
    ll ans=sub+kind*kind;
    rep(i,k,n){
        if(!used[td[i].second]){
            if(pq.empty())break;
            used[td[i].second]=1; kind++;
            sub+=td[i].first-pq.top(); pq.pop();
            chmax(ans,sub+1LL*kind*kind);
        }
    }
    printf("%lld\n",ans);
    return 0;
}