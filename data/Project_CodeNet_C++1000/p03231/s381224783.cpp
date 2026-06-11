#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    ll d=__gcd(n,m),ans=n*m/d;
    m/=d;d=n/d;
    bool maki=true;
    for(int i=0,j=0;i<n;i+=d,j+=m){
    	if(s[i]!=t[j])maki=false;
    }
    cout << ((maki)?ans:-1) <<endl;
    return 0;
}
