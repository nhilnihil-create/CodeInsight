#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};
int main(){
    int N,K;cin>>N>>K;
    vector<ll> x(N),y(N);
    vector<pll> p(N);
    for(int i=0;i<N;++i){
        cin>>x[i]>>y[i];
        p[i]=make_pair(x[i],y[i]);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    ll ans=(x[N-1]-x[0]+1)*(y[N-1]-y[0]+1);
    for(int i1=0;i1<N;++i1){
        for(int i2=i1+1;i2<N;++i2){
            for(int j1=0;j1<N;++j1){
                for(int j2=j1+1;j2<N;++j2){
                    int num=0;
                    for(int i=0;i<N;++i){
                        if(x[i1]<=p[i].first&&p[i].first<=x[i2]
                        &&y[j1]<=p[i].second&&p[i].second<=y[j2]){
                            num++;
                        }
                    }
                    if(num>=K){
                        ans=min(ans,(x[i2]-x[i1])*(y[j2]-y[j1]));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

