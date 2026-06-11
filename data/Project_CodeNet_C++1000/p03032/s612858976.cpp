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
    vector<int> V(N),tmp;
    for(int i=0;i<N;++i) cin>>V[i];
    int P=min(N,K);
    int ans=0;
    for(int i=1;i<=P;++i){
        for(int l=0;l<=i;++l){
            int r=i-l;
            tmp.clear();
            for(int j=0;j<l;++j) tmp.push_back(V[j]);
            for(int j=0;j<r;++j) tmp.push_back(V[N-1-j]);
            sort(tmp.begin(),tmp.end());
            int mn=lower_bound(tmp.begin(),tmp.end(),0)-tmp.begin();
            int sum=0;
            for(auto it:tmp) sum+=it;
            for(int j=0;j<min(mn,K-i);++j) sum-=tmp[j];
            ans=max(ans,sum);
        }
    }
    cout<<ans<<endl;
    return 0;
}