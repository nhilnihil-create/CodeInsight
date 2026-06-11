#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<62)-1
#define MAX 1000000000
signed main(){
    int N; cin>>N;
    vii A(N);
    rep(i,1,N){
        int X,Y; cin>>X>>Y;
        A[X-1].pb(Y-1);
        A[Y-1].pb(X-1);
    }
    vi F(N,-1);
    F[0]=0;
    queue<int> Q;
    Q.push(0);
    Q.push(-1);
    int cnt=1;
    while(Q.size()>1){
        int X=Q.front(); Q.pop();
        if(X==-1){
            cnt++;
            Q.push(-1);
        }
        else{
            rep(i,0,A[X].size()){
                int Y=A[X][i];
                if(F[Y]==-1){
                    F[Y]=cnt;
                    Q.push(Y);
                }
            }
        }
    }
    int mem=0,sum=0;
    int ans=0;
    rep(i,0,N){
        if(F[i]>sum){
            sum=F[i];
            mem=i;
        }
    }
    Q.pop();
    Q.push(mem);
    Q.push(-1);
    vector<bool> G(N,1);
    G[mem]=0;
    cnt=1;
    while(Q.size()>1){
        int X=Q.front(); Q.pop();
        if(X==-1){
            cnt++;
            Q.push(-1);
        }
        else{
            rep(i,0,A[X].size()){
                int Y=A[X][i];
                if(G[Y]){
                    G[Y]=0;
                    Q.push(Y);
                    ans=max(ans,cnt);
                }
            }
        }
    }
    if(ans%3==1) cout<<"Second"<<endl;
    else cout<<"First"<<endl;
}

