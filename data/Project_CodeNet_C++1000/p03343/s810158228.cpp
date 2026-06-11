//#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
using namespace std;
#define INF 1LL << 61
#define MAX 1LL << 30
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
//typedef pair<pair<int,int>,int> p;
#define bit(n, k) ((n >> k) & 1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad) / 2 / M_PI) * 360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};

signed main(void)
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);

    int N,K,Q,A[2100];
    vector<P> V;
    cin>>N>>K>>Q;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        V.push_back(P(A[i],i));
    }
    A[N+1]=-1;
    V.push_back(P(-1,0));
    sort(V.begin(),V.end());
    ll ans=INF;
    for(int i=0;i<N;i++){
        A[V[i].second]=-1;
        while(V[i+1].first==V[i].first){
            i++;
            A[V[i].second]=-1;
        }
        int now=1;
        vector<int> v;
        while(now<=N){
            int s=now;
            priority_queue<int> que;
            while(A[now]!=-1){
                que.push(-1*A[now]);
                now++;
            }
            int k=now-s;
            for(int j=0;j<k-K+1;j++){
                int x=que.top(); que.pop();
                v.push_back(-x);
            }
            now++;
        }
        sort(v.begin(),v.end());
        if((int)v.size()<Q) break;
        chmin(ans,v[Q-1]-v[0]);
    }
    cout<<ans<<endl;

}
