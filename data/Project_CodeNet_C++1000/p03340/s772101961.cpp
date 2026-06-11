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
const ll INF=2e9;
const ll MOD=1e9+7;
struct edge{
    int to;
    int cost;
};

int main(){
    int N;cin>>N;
    vector<int> A(N);
    for(int i=0;i<N;++i) cin>>A[i];
    ll ans=0;
    int right=0;
    ll sum=0;
    for(int left=0;left<N;++left){
        while(right<N&&(sum^A[right])==sum+A[right]){
            sum+=A[right];
            right++;
        }
        ans+=right-left;
        if(right==left) right++;
        else sum-=A[left];
    }
    cout<<ans<<endl;
    return 0;
}