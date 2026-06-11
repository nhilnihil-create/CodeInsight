/*
貪欲
後ろから見る
DP
順位表をチェック
二分探索
不変なもの・偶奇に注目

*/
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
#include<tuple>
#include<set>
using namespace std;
#define INF 1LL<<60
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,bool> P;
//typedef pair< pair<int,int>,pair<int,int> > p;
//#define int ll int main->signed main
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());

vector<int> V[110000],R[110000];
bool visit[110000];
vector<int> order;
int d[110000];
int ans[110000];

void dfs(int x){
    visit[x]=true;
    for(int i=0;i<(int)V[x].size();i++){
        int next=V[x][i];
        if(visit[next]) continue;
        dfs(next);
    }
    order.push_back(x);
}

int main(){
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N-1+M;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        V[a].push_back(b);
        R[b].push_back(a);
    }
    for(int i=0;i<110000;i++){
        visit[i]=false;
    }
    for(int i=0;i<N;i++){
        if(visit[i]) continue;
        dfs(i);
    }
    reverse(order.begin(),order.end());

    for(int i=0;i<N;i++){
        int x=order[i],a;
        if(i==0){
            ans[x]=-1; continue;
        }
        for(int j=0;j<(int)R[x].size();j++){
            int r=R[x][j];
            if(d[x]<d[r]+1){
                a=r;
                d[x]=d[r]+1;
            }
        }
        ans[x]=a;
    }
    for(int i=0;i<N;i++){
        cout<<ans[i]+1<<endl;
    }

    


}
