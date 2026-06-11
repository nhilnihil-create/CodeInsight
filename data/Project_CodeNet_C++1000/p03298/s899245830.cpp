#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=998244353;
int main(){
    ll n;
    string s;
    cin>>n>>s;
    string a=s.substr(0,n),b=s.substr(n,n);
    reverse(all(b));
    map<pair<string,string>,ll>m;
    map<pair<string,string>,ll>m2;
    rep(i,(1<<n)){
        string t="",u="";
        rep(j,n){
            if(i&(1<<j)){
                t=t+a[j];
            }else{
                u=u+a[j];
            }
        }
        pair<string ,string>k=mp(t,u);
        if(m.find(k)==m.end())m[k]=1;
        else m[k]++;
    }
    rep(i,(1<<n)){
        string t="",u="";
        rep(j,n){
            if(i&(1<<j)){
                t+=b[j];
            }else{
                u+=b[j];
            }
        }
        pair<string ,string>k=mp(t,u);
        if(m2.find(k)==m2.end())m2[k]=1;
        else m2[k]++;
    }
    ll ans=0;
    for(auto e:m){
        pair<string,string>k=e.first;
        if(m2.find(k)!=m2.end())ans+=e.second*(m2[k]);
    }
    cout<<ans<<endl;
}