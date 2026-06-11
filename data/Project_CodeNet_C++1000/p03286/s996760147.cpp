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
    ll n;
    cin>>n;
    ll tmp=n,add=0,two=2;
    int cnt=0,p=1;
    vi ans;
    if(tmp<0){
        tmp=-tmp;
        p=0;
    }
    while(tmp>0){
        ans.push_back(tmp%2);
        if(tmp%2==1&&cnt%2==p){
            tmp+=2;
        }
        tmp/=2;
        cnt++;
    }
    int a=ans.size();
    rep(i,a)cout<<ans[a-1-i];
    if(a==0)cout<<0;
    cout<<endl;
    return 0;
}