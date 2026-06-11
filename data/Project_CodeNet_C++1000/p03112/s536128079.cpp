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
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> P;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;

int main(){
    ll A,B,Q;cin>>A>>B>>Q;
    vector<ll> S(A+1),T(B+1);
    for(int i=1;i<=A;++i) cin>>S[i];
    for(int i=1;i<=B;++i) cin>>T[i];
    S.push_back(INF);T.push_back(INF);
    S[0]=T[0]=-INF;
    while(Q--){
        ll X;cin>>X;
        ll ans=INF;
        auto is=lower_bound(S.begin(),S.end(),X);
        auto it=lower_bound(T.begin(),T.end(),X);
        ans=min(ans,max(*is,*it)-X);
        ans=min(ans,abs(*is-*(it-1))+min(*is-X,X-*(it-1)));
        ans=min(ans,abs(*(is-1)-*it)+min(X-*(is-1),*it-X));
        ans=min(ans,X-min(*(is-1),*(it-1)));
        cout<<ans<<endl;
    }
    return 0;
}