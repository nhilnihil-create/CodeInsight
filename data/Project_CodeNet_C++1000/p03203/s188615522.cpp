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
#define INF (1ll<<60)
signed main(){
    int H,W,N; cin>>H>>W>>N;
    int ans=H;
    vi A(N),B(N);
    rep(i,0,N) cin>>A[i]>>B[i];
    set<pii> S;
    rep(i,0,N) S.insert(mp(A[i],B[i]));
    vi C(W+1);
    C[1]=1;
    REP(i,2,W){
        C[i]=C[i-1]+1;
        while(1){
            if(S.count(mp(C[i],i))) C[i]++;
            else break;
        }
    }
    rep(i,0,N){
        int X=A[i],Y=B[i];
        X--;
        if(X>=C[Y]){
            ans=min(ans,X);
        }
        //cout<<X<<" "<<Y<<" "<<C[Y]<<endl;
    }
    cout<<ans<<endl;
}