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
    vector<int>v(N);
    vector<int>c(N);
    vector<int>sub(N);
    int ans=0;
    rep(i,N)cin>>v.at(i);
    rep(i,N)cin>>c.at(i);
    rep(i,N){
        sub.at(i)=v.at(i)-c.at(i);
        if(sub.at(i)>=0)ans+=sub.at(i);
    }
    cout<<ans<<endl;

}