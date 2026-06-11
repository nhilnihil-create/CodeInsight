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
    int N,Q;cin>>N>>Q;
    string S;cin>>S;
    vector<int> C(N,0);
    for(int i=1;i<N;++i){
        C[i]+=C[i-1];
        if(S[i-1]=='A'&&S[i]=='C'){
            C[i]++;
        }
    }
    for(int i=0;i<Q;++i){
        int l,r;cin>>l>>r;
        l--;r--;
        cout<<C[r]-C[l]<<endl;
    }
    return 0;
}