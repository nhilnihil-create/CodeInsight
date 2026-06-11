//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (in i = 0; i < (in)(n); i++)
#define REP(i,a,b) for(in i=(in)(a);i<(in)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const in inf=1e9+7;
using P=pair<in,in>;
vector<in> dx={0,1,-1,0};
vector<in> dy={1,0,0,-1};
using T=tuple<in,in,in>;

in n;
vector<in> a(0),b(0);
vector<bool> seen(0);


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    cin>>n;
    a.resize(n);
    b.resize(n);
    seen.resize(n,0);
    rep(i,n) cin>>a[i]>>b[i];
    vector<T> x(n);
    rep(i,n) x[i]=T(a[i]+b[i],a[i],b[i]);
    sort(all(x));
    reverse(all(x));
    in ans=0ll;
    rep(i,n){
        if(i%2ll==0) ans +=get<1>(x[i]);
        else ans -=get<2>(x[i]);
    }
    cout<<ans<<endl;
}