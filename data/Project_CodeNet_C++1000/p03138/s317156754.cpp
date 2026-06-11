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
    ll N,K;cin>>N>>K;++K;
    vector<ll> A(N);
    for(int i=0;i<N;++i) cin>>A[i];
    ll ans=0;
    for(int d=50;d>=0;--d){
        ll tmp=0;
        ll mask=1LL<<d;
        if(!(K&mask)) continue;
        ll num=0;
        for(int e=50;e>=0;--e){
            ll num=0;
            mask=1LL<<e;
            for(int i=0;i<N;++i){
                if(A[i]&mask) ++num;
            }
            if(e>d){
                if(K&mask) tmp+=mask*(N-num);
                else tmp+=mask*num;
            }else if(e==d){
                tmp+=mask*num;
            }else{
                tmp+=mask*max(num,N-num);
            }
        }
        ans=max(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}