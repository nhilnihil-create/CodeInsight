#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 1000010
#define MAX_V 900010
using namespace std;
struct edge{
    int from,to,cost;
};
int m;
edge e[61];
void ins(int x,int y,int c){
    e[m]={x,y,c};
    m++;
}
main(){
    int n;cin>>n;
    
    int temp=20;
    while(temp>1){
        if(n==1){
            ins(1,temp,0);break;
        }
        else if(temp==2){
            rep(i,n)ins(1,2,i);
            temp--;
        }
        else if(n%2==0){
            ins(temp-1,temp,n/2);
            ins(temp-1,temp,0);
            n/=2;temp--;
        }
        else{
            ins(1,temp,n-1);
            ins(temp-1,temp,n/2);
            ins(temp-1,temp,0);
            n/=2;temp--;
        }
    }
    cout<<20<<" "<<m<<endl;
    if(m>60)return 0;
    rep(i,m){
        printf("%d %d %d\n",e[i].from,e[i].to,e[i].cost);
    }
    return 0;
}