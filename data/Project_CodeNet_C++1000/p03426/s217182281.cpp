#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

typedef long long ll;

const int INF = 1e+9;
const int H_MAX=300;
const int W_MAX=300;

int H,W,D;


vector<pair<int,int>> V(H_MAX*W_MAX+1);

int solve(int s,int e,vector<vector<int>> &memo){
    if(memo[s][e]<INF) return memo[s][e];
    int res;
    int x_cur,y_cur,x_next,y_next;
    if(e==0) return memo[s][e]=0;

    x_cur=V[s+D*(e-1)].first;
    y_cur=V[s+D*(e-1)].second;
    x_next=V[s+D*e].first;
    y_next=V[s+D*e].second;

    res=solve(s,e-1,memo)+abs(x_cur-x_next)+abs(y_cur-y_next); 
    return memo[s][e]=res;
}

int main(){
    cin >> H >> W >> D;
    vector<vector<int>> memo(D+1,vector<int>((H*W)/D+1,INF));

    int a;
    rep(i,H){
        rep(j,W){
            cin >> a;
            V[a]={i,j};
        }
    }

    


    int Q;
    int ans;
    cin >> Q;
    vector<int> L(Q),R(Q);

    rep(i,Q) cin >> L[i] >> R[i];
    int start,true_end,nise_end;
    rep(i,Q){
        start=L[i]%D;
        if(start==0) start+=D;
 
        true_end=(R[i]-start)/D;
        nise_end=(L[i]-start)/D;

        cout << solve(start,true_end,memo)-solve(start,nise_end,memo) << endl;
    }

    return 0;
}
