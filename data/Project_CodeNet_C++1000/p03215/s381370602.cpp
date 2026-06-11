#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;

#define ll long long
ll a[N];
multiset<ll>st;
int cnt(multiset<ll> &st,int p){
    int ans=0;
    for(auto x:st){
        if(x&(1ll<<p))ans++;
    }
    return ans;
}
multiset<ll> f(multiset<ll>st,int p){
    multiset<ll>ans;
    for(auto x:st){
        if(x&(1ll<<p)){
            ans.insert(x);
            //cout<<x<<' ';
        }
    }
    //cout<<endl;
    return ans;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++){
        ll cnt=0;
        for(int j=i;j<n;j++){
            cnt+=a[j];
            st.insert(cnt);
        }
    }
    /*
    for(auto x:st)
        cout<<x<<endl;*/

    ll ans=0;
    for(int i=45;i>=0;i--){
        //cout<<cnt(st,i)<<endl;
        if(cnt(st,i)>=k){
            ans+=(1ll<<i);
            st=f(st,i);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
