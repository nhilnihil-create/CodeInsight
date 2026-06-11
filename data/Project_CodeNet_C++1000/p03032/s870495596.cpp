#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=998244353;
#define chmin(x,y) x=min(x,y)

int main(void){
    int n,k;
    cin>>n>>k;
    vector<int> V(n);
    rep(i,n) cin>>V[i];
    int ans=0;
    //Aをl回、Bをr回行った後、小さいほうから
    //0より小さいものをk-l-r個まで戻す
    rep(l,n+1) rep(r,n+1){
        if(l+r>n || l+r>k) continue;
        vector<int> temp;
        int sum=0;
        rep(i,l) temp.push_back(V[i]), sum+=V[i];
        rep(i,r) temp.push_back(V[n-1-i]), sum+=V[n-1-i];
        sort(temp.begin(),temp.end());
        int m=temp.size();
        //itrにtempのうち0より小さいものの個数を代入
        auto itr=lower_bound(temp.begin(),temp.end(),0)-temp.begin();
        /*cout<<l<<" "<<r<<" "<<itr<<" "<<sum<<endl;
        rep(i,m) cout<<temp[i]<<" ";
        cout<<endl;*/
        if(itr>k-l-r) itr=k-l-r;
        rep(i,itr) sum-=temp[i];
        //cout<<sum<<endl<<endl;
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}