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
#define _GLIBCXX_DEBUG
const int inf=1e9+7;

int main(){
    int n,k;cin>>n>>k;
    vin x(n);
    rep(i,n)cin>>x[i];
    int minus=inf;
    rep(i,n){
        if(x[i]>0){
            minus=i;
            break;
        }
    }
    if(minus==0){
        cout<<x[k-1]<<endl;
        return 0;
    }
    if(minus==inf){
        cout<<-x[n-k]<<endl;
        return 0;
    }
    vin sumr(k);
    vin suml(k);
    int m=inf;
    for(int i=max(0,k-minus);i<min(k,n-minus);i++){
        if(i==k-1)break;
        if(2*x[minus+i]-x[minus-k+i+1]<m)m=2*x[minus+i]-x[minus-k+i+1];
    }
    for(int i=max(0,k-n+minus-1);i<min(k,minus);i++){
        if(i==k-1)break;
        if(-2*x[minus-1-i]+x[minus+k-i-2]<m)m=-2*x[minus-1-i]+x[minus+k-i-2];
    }
    if(k<=n-minus){
        m=min(m,x[minus+k-1]);
    }
    if(k<=minus){
        m=min(m,-x[minus-k]);
    }
    cout<<m<<endl;
}