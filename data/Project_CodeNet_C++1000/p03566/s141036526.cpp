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
    vi A(N+1),B(N+1);
    int sum=0;
    rep(i,0,N){
        cin>>A[i];
        sum+=A[i];
    }
    rep(i,0,N) cin>>B[i];
    vi C(sum+1);
    int memo=0,cnt=A[0];
    REP(i,1,sum){
        C[i]=min(C[i-1]+1,B[memo]);
        if(i==cnt){
            memo++;
            cnt+=A[memo];
            if(B[memo]<C[i]){
                C[i]=B[memo];
                for(int j=i-1;j>=0;j--){
                    if(C[j]>C[j+1]+1) C[j]=C[j+1]+1;
                    else break;
                }
            }
        }
    }
    double ans=0;
    memo=0;
    cnt=A[0];
    REP(i,1,sum){
        if(C[i-1]<C[i]){
            ans+=C[i-1];
            ans+=0.5;
        }
        else if(C[i-1]==C[i]){
            ans+=C[i];
            if(B[memo]>C[i]) ans+=0.25;
        }
        else{
            ans+=C[i];
            ans+=0.5;
        }
        if(cnt==i){
            memo++;
            if(memo<N) cnt+=A[memo];
        }
    }
    printf("%.10lf\n",ans);
}
