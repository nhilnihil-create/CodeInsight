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
    ll n;cin>>n;
    string s;cin>>s;
    reverse(all(s));
    vector<ll>c(n),m(n),cm(n),cmd(n);
    if(s[0]=='C')c[0]=1;
    if(s[0]=='M')m[0]=1;
    REP(i,1,n){
        if(s[i]=='C'){
            c[i]=c[i-1]+1;
            m[i]=m[i-1];
            cm[i]=cm[i-1];
        }
        else if(s[i]=='M'){
            c[i]=c[i-1];
            m[i]=m[i-1]+1;
            cm[i]=c[i-1]+cm[i-1];
        }
        else if(s[i]=='D'){
            c[i]=c[i-1];
            m[i]=m[i-1];
            cm[i]=cm[i-1];
            cmd[i]=cm[i-1];
        }else{
            c[i]=c[i-1];
            m[i]=m[i-1];
            cm[i]=cm[i-1];
        }
    }
    ll q;cin>>q;
    while(q){
        q--;
        ll k;cin>>k;
        ll ans=0;
        rep(i,n){
            if(s[i]=='D'){
                if(i-k<0){
                    ans+=cmd[i];
                }else{
                    ans+=cmd[i]-cm[i-k]-c[i-k]*(m[i]-m[i-k]);
                }
            }
        }
        cout<<ans<<endl;
    }
}