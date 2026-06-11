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
const ll MOD=1e9+7;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=1e18;

int main(){
    int N,C;cin>>N>>C;
    int D[C][C];
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++) cin>>D[i][j];
    }
    int c[N][N];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>c[i][j];
            c[i][j]--;
        }
    }
    map<int,ll> m0,m1,m2;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if((i+j)%3==0) m0[c[i][j]]++;
            else if((i+j)%3==1) m1[c[i][j]]++;
            else m2[c[i][j]]++;
        }
    }
    ll  ans=INF;
    for(int i=0;i<C;i++){
        for(int j=0;j<C;j++){
            for(int k=0;k<C;k++){
                if(i==j||j==k||k==i) continue;
                ll sum=0;
                for(auto it:m0){
                    sum+=D[it.first][i]*it.second;
                }
                for(auto it:m1){
                    sum+=D[it.first][j]*it.second;
                }
                for(auto it:m2){
                    sum+=D[it.first][k]*it.second;
                }
                ans=min(ans,sum);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}