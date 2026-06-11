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
typedef long long ll;
typedef pair<int,ll> p;
typedef pair<pii,int> P;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;

vector<int> prime(1e5+1,1);
vector<int> likenum(1e5+1,0);
void solve(){
    prime[0]=prime[1]=0;
    for(int i=2;i<=1e5;++i){
        if(prime[i]==1){
            for(int j=2*i;j<=1e5;j+=i){
                prime[j]=0;
            }
        }
    }
    for(int i=3;i<=1e5;++i){
        if(prime[i]==1&&prime[(i+1)/2]==1){
            likenum[i]=1;
        }
    }
    for(int i=1;i<=1e5;++i){
        likenum[i]+=likenum[i-1];
    }
}
int main(){
    int q;cin>>q;
    solve();
    while(q--){
        int l,r;cin>>l>>r;
        cout<<likenum[r]-likenum[l-1]<<endl;
    }
    return 0;
}