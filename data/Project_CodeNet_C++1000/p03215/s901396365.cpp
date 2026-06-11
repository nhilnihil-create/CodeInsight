#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
map<string,int> mp;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
int n,k;
cin>>n>>k;
vector<ll> a(n),sum(n+1,0);
for(int i=0;i<n;i++)cin>>a.at(i);
for(int i=0;i<n;i++)sum.at(i+1)=a.at(i)+sum.at(i);
vector<ll> tmp;
for(int i=1;i<n+1;i++){
    for(int j=0;j<i;j++){
        tmp.push_back(sum.at(i)-sum.at(j));
    }
}
ll ans;
for(ll bit=60;bit>=0;bit--){
    vector<ll> res;
    for(int i=0;i<tmp.size();i++){
        if(tmp.at(i)&(1ll<<bit))res.push_back(tmp.at(i));
    }
    if(res.size()>=k){
           tmp=res;
    }
}
ans=tmp.at(0);
for(int i=1;i<tmp.size();i++){
    ans&=tmp.at(i);
}
cout<<ans<<endl;
}
