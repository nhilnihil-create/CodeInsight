#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

ll n,a[200010]={0};
vector<ll>b;

int main(){
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    b.resize(n);
    for(int i=0;i<n;++i){
        cin>>b[i];
    }

    
    ll ans=0;
    for(int i=0;i<29;++i){
        vector<ll>c;
        ll key=(1<<i);
        for(int k=0;k<n;++k){
            c.push_back(b[k]%(2*key));
        }
        sort(c.begin(),c.end());
        ll cnt=0;
        for(int j=0;j<n;++j){
            ll d=a[j]%(2*key);
            cnt+=(ll)(lower_bound(c.begin(),c.end(),2*key-d)-lower_bound(c.begin(),c.end(),key-d));
            cnt+=(ll)(lower_bound(c.begin(),c.end(),4*key-d)-lower_bound(c.begin(),c.end(),3*key-d));
        }
        ans+=(cnt%2)*key;
    }

    cout<<ans<<endl;

    return 0;
}