#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';
using namespace std;

#define NODE_NUM 100
struct Node{
    ll ord;
    ll low;
    ll depth;
    bool visited;
    vector<ll> par;
};

Node node[NODE_NUM];
bool edges[NODE_NUM][NODE_NUM];
ll ORD;
void dfs(ll index){
    node[index].ord=ORD;
    ORD++;
    node[index].low=node[index].ord;
    node[index].visited=true;
    rep(i, node[index].par.size()){
        if(node[node[index].par[i]].visited==false){
            edges[node[index].par[i]][index]=true;
            edges[index][node[index].par[i]]=true;
            //cout<<node[index].par[i]<<"%"<<index<<endl;
            dfs(node[index].par[i]);
            node[index].low=min(node[index].low, node[node[index].par[i]].low);
        }
        else if(edges[index][node[index].par[i]]==false){
            //cout<<node[index].par[i]<<"#"<<index<<endl;
            node[index].low=min(node[index].low, node[node[index].par[i]].ord);
            edges[index][node[index].par[i]]=true;
            edges[node[index].par[i]][index]=true;
        }
    }
    //cout<<index<<sp<<node[index].ord<<sp<<node[index].low<<endl;
}
void dfs_refresh(void){
    rep(i, NODE_NUM) rep(j, NODE_NUM) edges[i][j]=false;
    ORD=0;
    rep(i, NODE_NUM){
        node[i].visited=false;
    }
}

int main(void){
    ll N, M;
    cin>>N>>M;
    ll A[100], B[100];
    rep(i, M){
        cin>>A[i]>>B[i];
        node[A[i]-1].par.push_back(B[i]-1);
        node[B[i]-1].par.push_back(A[i]-1);
    }
    dfs_refresh();
    dfs(0);
    ll count=0;
    rep(i, M){
        if(node[A[i]-1].ord<node[B[i]-1].low || node[B[i]-1].ord<node[A[i]-1].low) count++;
    }
    cout<<count<<endl;
    return 0;
}