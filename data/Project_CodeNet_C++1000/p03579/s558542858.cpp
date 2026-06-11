#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cstdio>
#include<cmath>
using namespace std;
//#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
int MOD=1000000007;
struct Node{
    int num;
    int no;
    int c;
    vector<Node*> edge;
    void build(int i){
        no=i;
        num=edge.size();
        c=3;
    }
};
signed main(){
    int n,m;cin>>n>>m;
    vector<int> a(m);
    vector<int> b(m);
    vector<Node> node(n+1);
    rep(i,m){
        cin>>a[i]>>b[i];
        node[a[i]].edge.push_back(&node[b[i]]);
        node[b[i]].edge.push_back(&node[a[i]]);
    }
    rep1(i,n){
        node[i].build(i);
    }
    bool binary_graph=true;
    queue<Node> que;
    node[1].c=1;que.push(node[1]);
    while(!que.empty()){
        Node buf=que.front();que.pop();
        rep(i,buf.num){
            if(buf.edge[i]->no==buf.no)continue;
            //printf("node[%d].c=%d\n",buf.edge[i]->no,buf.edge[i]->c);
            if(buf.edge[i]->c==3){
                buf.edge[i]->c=buf.c*2%3;
                que.push(*buf.edge[i]);
            }
            else{
                if(buf.c==buf.edge[i]->c){
                    binary_graph=false;
                    goto FINE;
                }
                else{
                    //continue;
                }
            }
        }
    }
    FINE:
    if(binary_graph){
        int T=0;int F=0;
        rep1(i,n){
            if(node[i].c==1){
                T++;
            }
            else F++;
        }
        int sub=0;
        rep(i,m){
            if(node[a[i]].c!=node[b[i]].c){
                sub++;
            }
        }
        //cout<<sub<<endl;
        //cout<<T*F<<endl;
        long long res=T;
        res*=F;
        res-=sub;
        cout<<res<<endl;
    }
    else{
        long long res=n;
        res*=(n-1);
        res/=2;
        res-=m;
        cout<<res<<endl;
    }
    rep1(i,n){
        //printf("c[%d]=%d\n",i,node[i].c);
    }
    if(binary_graph){
        //cout<<"Yes"<<endl;
    }
    return 0;
}