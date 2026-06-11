#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define fi first
#define se second
#define rep(i,s,n) for(int i = s;i<n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
const ll MOD=1000000007,INF=1e18;

int T;
int A,B,C,D;

int gcd(int x,int y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int lcm(int x, int y)
{
    return (x * y / gcd(x, y));
}

signed main() {
    IOS();
    cin>>T;
    rep(i,0,T){
        cin>>A>>B>>C>>D;
        if(A<B||B>D){
            cout<<"No"<<endl;
            continue;
        }
        int x=gcd(B,D);
        if(B-x+A%x<=C)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}