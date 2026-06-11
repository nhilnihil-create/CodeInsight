//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
    ll n,h; cin>>n>>h;
    vector<ll>a(n);
    vector<ll>b(n);
    rep(i,n){
        cin>>a[i]>>b[i];
    }
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    ll A=a[0];
    ll cnt=0;
    ll ans=0;
    rep(i,n){
        if(A<b[i]){
            cnt++;
            ans+=b[i];
            if(ans>=h){
                cout<<cnt<<endl;
                return 0;
            }
    }
    else break;
}
ll remain=h-ans;
cnt+=(h-ans+A-1)/A;
cout<<cnt<<endl;
}

















































