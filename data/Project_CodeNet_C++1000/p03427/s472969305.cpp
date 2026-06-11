//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;
ll keta(ll x){
    ll cnt=1;
    while(x/10>0){
        x/=10;
        cnt++;
    }
    return cnt;
}
ll sumdigit(ll y){
    ll sum=0;
    while(y>0){
        sum+=y%10;
        y/=10;
    }
    return sum;
}
int main(){
    ll N; cin>>N;
    //cout<<keta(N)<<endl;
    ll k=keta(N);
    ll ans =1;
    rep(i,k){
        ans*=10;
    }
    ll minus=ans/10;
    ans--;
    //cout<<minus<<" "<<ans<<endl;
    while(ans>N){
        ans-=minus;
    }
    //cout<<ans<<endl;
    cout<<sumdigit(ans)<<endl;
}
