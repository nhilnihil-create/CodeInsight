#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;
ll const mod=998244353;
const ll MAX=300000;
using vi=vector<int>;
using vc=vector<char>;
using vs=vector<string>;
using vvi =vector<vector<int>>;
using vvc=vector<vector<char>>;
using vvp =vector<vector<P>>;
int main(){
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    mp[0]=1;
    ll sum=0,ans=0;
    rep(i,n){
        int a;
        cin>>a;
        sum+=a;
        ans+=mp[sum%m];
        mp[sum%m]++;
    }
    cout<<ans<<endl;
    return 0;
}