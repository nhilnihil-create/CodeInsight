#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll i,j,k,l;

int main(){
    ll n,h,sum=0;cin>>n>>h;
    vector<ll> a(n),b(n);
    for(i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(i=0;i<n;i++){
        if(b[i]<=a[n-1]){b[i]=-1;}//最大の通常攻撃より小さいdamageなら投げつけない
        else{sum+=b[i];}
    }

    ll ans=0,num=n-1;
    while(h>0 && num>=0 && b[num]!=-1){
        h-=b[num--];
        ans++;
    }

    if(h<=0){cout<<ans<<endl;return 0;}

    ans+=(h+a[n-1]-1)/a[n-1];

    cout<<ans<<endl;
    return 0;
}