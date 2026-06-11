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
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    ll x,y,z,k;cin>>x>>y>>z>>k;
    vll a(x),b(y),c(z);
    rep(i,x)cin>>a[i];
    rep(i,y)cin>>b[i];
    rep(i,z)cin>>c[i];
    sort(all(a));reverse(all(a));
    sort(all(b));reverse(all(b));
    sort(all(c));reverse(all(c));
    ll L=0;ll R=3e10+1;ll M,l,r,m,tmp,sum;
    while(R-L>1){
        M=(L+R)/2;
        sum=0;
        rep(i,x)rep(j,y){
            l=-1;r=z;
            tmp=a[i]+b[j];
            while(r-l>1){
                m=(l+r)/2;
                if(tmp+c[m]<M)r=m;
                else l=m;
            }
            sum+=l+1;//M以上になるcの個数
        }
        if(sum<k)R=M;
        else L=M;
    }
    priority_queue<ll> pq;
    rep(i,x)rep(j,y){
        l=-1;r=z;
        tmp=a[i]+b[j];
        while(r-l>1){
            m=(r+l)/2;
            if(tmp+c[m]<L)r=m;
            else l=m;
        }
        rep(h,l+1)pq.push(tmp+c[h]);
    }
    rep(i,k){
        cout<<pq.top()<<endl;
        pq.pop();
    }
}