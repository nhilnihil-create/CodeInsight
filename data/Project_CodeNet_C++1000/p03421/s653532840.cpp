#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 123456789012

void solve(ll n,ll a,ll b){
    if(a*b==n){
        for(ll i=b-1;i>=0;i--){
            for(int j=1;j<=a;j++){
                cout<<i*a+j<<" ";
            }
        }
    }
    else if(a*(b-1)>=n-1){
        cout<<n<<" ";
        solve(n-1,a,b-1);
    }
    else{
        int u=n-a*(b-1);
        for(ll i=-u+1;i<=0;i++){
            cout<<n+i<<" ";
        }
        solve(n-u,a,b-1);
    }
}

int main(){
    ll i,j;
    ll n,a,b;
    cin>>n>>a>>b;
    if(a+b-1>n){
        cout<<-1<<endl;
        return 0;
    }
    if(a*b<n){
        cout<<-1<<endl;
        return 0;
    }
    solve(n,a,b);
}