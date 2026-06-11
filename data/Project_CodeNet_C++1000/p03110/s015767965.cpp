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
    int N;cin>>N;
    vector<double>x(N);
    vector<string>u(N);
    double ans=0;
    rep(i,N){
        cin>>x.at(i)>>u.at(i);
    }
    rep(i,N){
        if(u.at(i)=="JPY"){
            ans+=x.at(i);
        }else{
            ans+=x.at(i)*380000.0;
        }
    }
    cout<<ans<<endl;

}