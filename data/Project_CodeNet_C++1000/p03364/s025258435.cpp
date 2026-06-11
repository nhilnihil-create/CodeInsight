#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    vector<string>s(2*n),ts(2*n,"");
    rep(i,n){
        string ss;cin>>ss;
        ss+=ss;
        s[i]=ss;
        s[i+n]=s[i];
    }
    rep(i,2*n){
        rep(j,2*n){
            ts[i]+=s[j][i];
        }
    }
    ll cnt=0;
    rep(a,n){
        bool f=1;
        rep(i,n){
            rep(j,n){
                if(s[a+i][j]!=s[a+j][i])f=0;
            }
        }
        if(f)cnt++;
    }
    cout<<cnt*n<<endl;
}