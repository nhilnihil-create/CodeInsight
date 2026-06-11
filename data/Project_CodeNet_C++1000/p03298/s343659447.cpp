#include <bits/stdc++.h>
#define FI first
#define SE second
#define PB push_back
#define MA make_pair
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define co(i) cout<<(i)<<endl
#define fcout cout<<fixed<<setprecision(10)
#define uni(i) i.erase(unique(i.begin(), i.end()), i.end());
#define all(i) i.begin(),i.end()
using namespace std;

const int INF=1e9+7;
const int MOD=1e9+7;

#define PA pair<string,string>

int main(){
    int n; cin>>n;
    string s; cin>>s;
    map<PA,ll> m;
    ll ans=0;
    FOR(i,0,1<<n){
        string sk,sl;
        FOR(j,0,n){
            if((i>>j)&1) sk+=s[j];
            else sl+=s[j];
        }
        m[PA(sk,sl)]++;
        //cout<<sk<<" "<<sl<<endl;
    }
    //cout<<endl;
    FOR(i,0,1<<n){
        string sk,sl;
        FOR(j,0,n){
            if((i>>j)&1) sk=s[n+j]+sk;
            else sl=s[n+j]+sl;
        }
        //cout<<sk<<" "<<sl<<endl;
        ans+=m[PA(sk,sl)];
    }
    co(ans);
}
