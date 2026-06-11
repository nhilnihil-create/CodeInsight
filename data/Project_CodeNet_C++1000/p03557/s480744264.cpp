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
    int n;cin>>n;
    vin a(n),b(n+1),c(n+1);
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];
    b[n]=inf;c[n]=inf;
    sort(all(b));
    sort(all(c));
    map<int,int> numb;numb[b[0]]=n;
    map<int,int> numc;numc[c[0]]=n;
    rep2(i,1,n)if(b[i]!=b[i-1])numb[b[i]]=n-i;
    rep2(i,1,n)if(c[i]!=c[i-1])numc[c[i]]=n-i;
    map<int,ll> btoc;
    ll tmp=0;
    for(int i=n-1;i>=0;i--){
        btoc[b[i]]=tmp+(ll)numc[*upper_bound(all(c),b[i])];
        tmp=btoc[b[i]];
    }
    ll sum=0;
    rep(i,n)sum+=btoc[*upper_bound(all(b),a[i])];
    cout<<sum<<endl;
}