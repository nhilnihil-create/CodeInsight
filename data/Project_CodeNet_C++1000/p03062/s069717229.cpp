#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

int main(){
    ll n; cin>>n;
    vector<ll>a(n);
    ll cnt=0;
    ll sum=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]<=0){
            cnt++;
            a[i]*=-1;
        }
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    if(cnt%2==0){
        cout<<sum<<endl;
    }
    else{
        cout<<sum-2*a[0]<<endl;
    }
}






































