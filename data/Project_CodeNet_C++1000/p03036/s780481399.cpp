#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    int r,d,x2000;cin>>r>>d>>x2000;
    vector<ll>x(10);
    rep(i,10){
        if(i==0){
            x.at(i)=r*x2000-d;
        }else{
            x.at(i)=r*x.at(i-1)-d;
        }
        cout<<x.at(i)<<endl;
    }
}
