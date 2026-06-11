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
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
ll gcd(ll a,ll b){
    if(min(a,b)==0)return max(a,b);
    if(max(a,b)%min(a,b)==0)return min(a,b);
    return gcd(min(a,b),max(a,b)%min(a,b));
}
int main(){
    ll t;cin>>t;
    while(t){
        t--;
        ll a,b,c,d;cin>>a>>b>>c>>d;
        bool f=1;
        if(a<b)f=0;
        else if(d<b)f=0;
        else if(a%b>c)f=0;
        else if(c<b-1){
            ll s=gcd(d,b);
            if(s){
                if((c+1-a%b)/s<(b-1-a%b)/s||(c+1-a%b)%s==0)f=0;
            }
        }
        cout<<(f?"Yes":"No")<<endl;
    }
}