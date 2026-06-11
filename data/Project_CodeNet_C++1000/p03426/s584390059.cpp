#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t CalcD(pair<int,int> X, pair<int,int> Y){
    return abs(X.first-Y.first)+abs(X.second-Y.second);
}

int main(){
    int H,W,D; cin>>H>>W>>D;
    vector<pair<int,int>> A(H*W);
    rep(h,0,H)rep(w,0,W){
        int a; cin>>a;
        A.at(a-1)=make_pair(h,w);
    }

    vector<int> Ans(H*W,0);
    rep(d,0,D){
        for(int i=d; i+D<H*W; i+=D){
            Ans.at(i+D)+=Ans.at(i)+CalcD(A.at(i),A.at(i+D));
        }
    }

    int Q; cin>>Q;
    rep(q,0,Q){
        int l,r; cin>>l>>r;
        l--; r--;

        int64_t ans=Ans.at(r)-Ans.at(l);
        cout<<ans<<endl;
    }
}