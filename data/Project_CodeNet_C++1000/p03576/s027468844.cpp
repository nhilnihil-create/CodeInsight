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
    int n,k;cin>>n>>k;
    vll x(n),y(n);
    rep(i,n)cin>>x[i]>>y[i];
    ll area=5*INF;int res;ll a,b,c,d;
    rep(i,n)rep(j,n)rep(l,n)rep(m,n){//left x,right x,under y,up y
       a=x[i];b=x[j];c=y[l];d=y[m];
       res=0;
       rep(h,n){
           if(a<=x[h]&&x[h]<=b&&c<=y[h]&&y[h]<=d)res++;
       }
       if(res>=k)area=min(area,(b-a)*(d-c));
   }
   cout<<area<<endl;
}