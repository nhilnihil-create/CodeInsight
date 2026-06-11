#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=998244353;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;cin>>n;
    if(n==0){
        cout<<0<<endl;
        return 0;
    }
    ll now=33;
    vector<ll>ma(33),mi(33);
    ma[0]=1;
    mi[1]=-2;
    ma[1]=1;
    REP(i,2,33){
        if(i%2==0){
            ma[i]=ma[i-1]+(1LL<<i);
            mi[i]=mi[i-1];
        }else{
            mi[i]=mi[i-1]-(1LL<<i);
            ma[i]=ma[i-1];
        }
        //cout<<i<<' '<<ma[i]<<' '<<mi[i]<<endl;
    }
    string s="";
    while(now>0){
        ll k=(1LL<<now);
        if(now%2)k=-k;
        if(n>=mi[now-1]&&n<=ma[now-1]){
            s+='0';
        }else{
            n-=k;
            s+='1';
        }
        now--;
        //cout<<now<<' '<<n<<endl;
    }
    if(n==1){
        s+='1';
    }else{
        s+='0';
    }
    bool f=0;
    rep(i,s.size()){
        if(f)cout<<s[i];
        else{
            f=(s[i]=='1');
            if(f)cout<<s[i];
        }
    }
    cout<<endl;
}