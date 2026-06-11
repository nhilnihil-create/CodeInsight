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
    int H,W,D;cin>>H>>W>>D;
    int A[H][W];
    vector<int> X(H*W+1,0),Y(H*W+1,0); 
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            cin>>A[i][j];
            X[A[i][j]]=i;
            Y[A[i][j]]=j;
        }
    }
    vector<int> SX(H*W+1,0),SY(H*W+1,0);
    for(int i=D+1;i<=H*W;++i){
        SX[i]=SX[i-D]+abs(X[i]-X[i-D]);
        SY[i]=SY[i-D]+abs(Y[i]-Y[i-D]);
    }
    int Q;cin>>Q;
    while(Q--){
        int L,R;cin>>L>>R;
        cout<<(SX[R]-SX[L])+(SY[R]-SY[L])<<endl;
    }
    return 0;
}