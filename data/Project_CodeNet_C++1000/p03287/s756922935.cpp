#include <bits/stdc++.h>
using ll=long long;
using namespace std;
ll INF=1000000000000000;
ll mod=1000000007;
ll i,j,k,l;

vector<ll> sum;
void pre_process(vector<ll> &a,vector<ll> &s){//累積和のvector
    ll n=(ll)a.size();
    s.assign(n+1,0);
    for(i=0;i<n;i++){
        s[i+1]=s[i]+a[i];
    }
}
ll query(ll i,ll j,vector<ll> &s){//区間[i,j]の和
    return (s[j]-s[i]);
}

int main(){
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    pre_process(a,sum);//累積和の作成→2つsumを選んだときにあまりが同じなら条件を満たす
    
    //mod mで分類
    for(i=0;i<=n;i++){
        sum[i]%=m;
    }

    sort(sum.begin(),sum.end());//同じあまりのものを数えたいのでsort
    
    ll same_mod=1;
    vector<ll> same;
    for(i=0;i<n;i++){//同じあまりのものを探す
        if(sum[i]==sum[i+1]){
            same_mod++;//同じあまりのものの個数
            if(i==n-1){same.push_back(same_mod);}
        }else{
            same.push_back(same_mod);
            same_mod=1;
        }
    }

    ll ans=0;
    for(i=0;i<same.size();i++){//同じあまりのものから2つとるのでnC2
        ans+=same[i]*(same[i]-1)/2;
    }

    cout<<ans<<endl;
    return 0;
}