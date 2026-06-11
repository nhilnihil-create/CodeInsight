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
    int K; cin>>K;
    priority_queue<pii,vector<pii>,greater<pii>> Q;
    vi F(K,INF);
    rep(i,1,10){
        if(F[i%K]>i){
            Q.push(mp(i,i%K));
            F[i%K]=i;
        }
    }
    while(Q.size()>0){
        int X=Q.top().first,Y=Q.top().second; Q.pop();
        if(Y==0){
            cout<<X<<endl;
            break;
        }
        if(F[Y]<X) continue;
        rep(i,0,10){
            int Z=(Y*10+i)%K,P=X+i;
            if(F[Z]>P){
                F[Z]=P;
                Q.push(mp(P,Z));
            }
        }
    }
}
