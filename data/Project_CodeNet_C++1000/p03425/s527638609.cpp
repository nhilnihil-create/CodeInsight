#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<(n);i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;

int main(){
    int n;cin>>n;
    ll m=0,r=0,c=0,a=0,h=0;
    rep(i,n){
        string s;cin>>s;
        if(s[0]=='M')m++;
        if(s[0]=='A')a++;
        if(s[0]=='R')r++;
        if(s[0]=='C')c++;
        if(s[0]=='H')h++;
    }
    ll ans = m*a*r;
    ans+=m*a*c;
    ans+=m*a*h;
    ans+=m*r*c;
    ans+=m*r*h;
    ans+=m*c*h;
    ans+=a*r*c;
    ans+=a*r*h;
    ans+=a*c*h;
    ans+=r*c*h;
    cout<<ans<<endl;
}
