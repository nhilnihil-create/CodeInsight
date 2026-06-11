#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<map>
#include<queue>
using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};



#define int ll
signed main(){
    int n;
    cin>>n;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        if(x<y)swap(x,y);
    int r=floor(sqrt(x*y));
    if(r*(r+1)<x*y)cout<<2*r-1<<endl;
    else if(r*r<x*y)cout<<2*r-2<<endl;
    else cout<<2*r-3+(r==x)<<endl;
    }
    return 0;
}