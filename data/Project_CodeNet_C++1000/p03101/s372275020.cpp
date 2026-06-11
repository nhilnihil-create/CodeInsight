#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(i,s,e) for(ll i=s;i<e;i++ )
typedef pair<ll,ll> P;
const ll mod = 1000000007;
const ll INF = 100000000000009;
ll i;

int main(){
    ll H,W,h,w;
    cin>>H>>W>>h>>w;
    cout<<H*W-H*w-W*h+h*w<<endl;
}

