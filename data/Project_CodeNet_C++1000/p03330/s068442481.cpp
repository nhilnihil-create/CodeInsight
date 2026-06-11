#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,c;cin>>n>>c;
    vvin d(c,vin(c));
    rep(i,c)rep(j,c)cin>>d[i][j];
    vvin color(n,vin(n));
    vin zero(c),one(c),two(c);
    rep(i,n)rep(j,n){
        cin>>color[i][j];
        if((i+j)%3==0){
            rep(k,c)zero[k]+=d[color[i][j]-1][k];
        }
        else if((i+j)%3==1){
            rep(k,c)one[k]+=d[color[i][j]-1][k];
        }
        else{
            rep(k,c)two[k]+=d[color[i][j]-1][k];
        }
    }
    int ans=inf;
    rep(i,c)rep(j,c)rep(k,c){
        if(i==j||j==k||k==i)continue;
        ans=min(ans,zero[i]+one[j]+two[k]);
    }
    cout<<ans<<endl;
}