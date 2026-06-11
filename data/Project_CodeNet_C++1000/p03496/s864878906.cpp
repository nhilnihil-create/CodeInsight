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
typedef pair<int,ii> pii;
typedef long long ll;
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
    vector<ll> A(N);
    for(int i=0;i<N;++i) cin>>A[i];
    bool p=true,n=true;
    for(int i=0;i<N;++i){
        if(A[i]<0) p=false;
        if(A[i]>0) n=false;
    }
    int cnt=0;
    vector<ii> ans;
    if(!p&&!n){
        int mn=1,mx=-1;
        int imx=-1,imn=-1;
        for(int i=0;i<N;++i){
            if(mx<A[i]){
                mx=A[i];
                imx=i;
            }
            if(mn>A[i]){
                mn=A[i];
                imn=i;
            }
        }
        if(abs(mx)>=abs(mn)){
            for(int i=0;i<N;++i){
                A[i]+=mx;
                cnt++;
                ans.push_back(ii(imx+1,i+1));
            }
            p=true;
        }else{
            for(int i=0;i<N;++i){
                A[i]+=mn;
                cnt++;
                ans.push_back(ii(imn+1,i+1));
            }
            n=true;
        }
    }
    if(p){
        for(int i=1;i<N;++i){
            cnt++;
            ans.push_back(ii(i,i+1));
        }
    }
    if(n){
        for(int i=N;i>1;--i){
            cnt++;
            ans.push_back(ii(i,i-1));
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<(int)ans.size();++i){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
    return 0;
}