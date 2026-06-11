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
    int n,m;cin>>n>>m;
    vin a(n);rep(i,n)cin>>a[i];
    vpii d(m);
    int b,c;
    rep(i,m){
        cin>>b>>c;
        d[i]=mp(c,b);
    }
    sort(all(a));
    sort(all(d));reverse(all(d));
    int j=0;int res;
    rep(i,m){
        res=0;
        while(res<d[i].second&&a[j]<d[i].first){
            a[j]=d[i].first;
            j++;
            res++;
        }
        if(res!=d[i].second)break;
    }
    ll sum=0;
    rep(i,n)sum+=(ll)a[i];
    cout<<sum<<endl;
}