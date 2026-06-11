#include<bits/stdc++.h>
using namespace std;

using ll=long long;
int main(){
    int n;
    ll X;
    cin>>n>>X;
    vector<ll> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    vector<ll> sum(n+1);
    partial_sum(x.begin(),x.end(),sum.begin()+1);
    ll res=1e18;
    for(int i=n;i>=1;i--){
        ll sc=X*i+X*n;
        int ub=n;
        int k=1;
        // cerr<<sc<<endl;
        while(ub>0){
            int lb=max(ub-i,0);
            // cerr<<ub<<" "<<lb<<endl;
            sc+=(sum[ub]-sum[lb])*(2*k+1);
            if(sc>res) break;
            if(k==1) sc+=(sum[ub]-sum[lb])*2;
            k++;
            ub=lb;
            // cerr<<sc<<endl;
        }
        // cerr<<sc<<endl;
        res=min(res,sc);
    }
    cout<<res<<endl;
    return 0;
}