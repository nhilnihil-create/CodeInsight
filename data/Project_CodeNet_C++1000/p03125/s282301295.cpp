#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(a,j,n) for(ll i=a;i<j;i=i+n )
typedef pair<ll,ll> P;
const ll mod = 1000000007;
const ll INF = 1000000009;
ll i;

int main(){
    ll A,B;
    cin>>A>>B;
    if(B%A)cout<<B-A;
    else cout<<A+B;
    cout<<endl;
}