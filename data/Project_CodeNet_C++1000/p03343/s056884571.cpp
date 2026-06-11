#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define INF 1LL << 55
#define MAX (1LL << 31) -1
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;
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

bool flag[2100];

signed main(){
    int N,K,Q;
    cin>>N>>K>>Q;
    vector<ll> A(N+1);
    for(int i=1;i<=N;i++) cin>>A[i];
    vector<P> V;
    for(int i=1;i<=N;i++){
        V.push_back(P(A[i],i));
    }
    sort(V.begin(),V.end());
    ll ans=INF;
    flag[N+1]=true;
    for(int i=0;i<N;i++){
        priority_queue<ll> que;
        vector<ll> v;
        int count=0;
        for(int j=1;j<=N+1;j++){
            if(flag[j]){
                for(int k=0;k<count-K+1;k++){
                    v.push_back(que.top()*(-1));
                    que.pop();
                }
                while(!que.empty()) que.pop();
                count=0;
            }else que.push(-A[j]),count++;
        }
        sort(v.begin(),v.end());
        if(v.size()>=Q) chmin(ans,v[Q-1]-v[0]);
        flag[V[i].second]=true;
    }
    cout<<ans<<endl;

}