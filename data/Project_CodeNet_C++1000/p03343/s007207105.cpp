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
    int N,K,Q; cin>>N>>K>>Q;
    vi A(N);
    rep(i,0,N) cin>>A[i];
    int ans=INF;
    rep(i,0,N){
        priority_queue<int,vi,greater<int>> que,queu;
        rep(j,0,N){
            if(A[j]<A[i]){
                int P=que.size();
                REP(k,0,P-K){
                    queu.push(que.top());
                    que.pop();
                }
                while(que.size()>0) que.pop();
            }
            else que.push(A[j]);
        }
        int P=que.size();
        REP(k,0,P-K){
            queu.push(que.top());
            que.pop();
        }
        if((int)queu.size()>=Q){
            int X=0,Y=A[i];
            rep(j,0,Q){
                X=max(queu.top(),X);
                queu.pop();
            }
            ans=min(ans,X-Y);
        }
    }
    cout<<ans<<endl;
}
