#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    int n,k,q;
    string s;
    cin>>n>>s>>q;
    rep(j,q){
        cin>>k;
        ll d=0,m=0,dm=0,ans=0;
        rep(i,n){
            if(i>=k){
                if(s[i-k]=='D') d--,dm-=m;
                if(s[i-k]=='M') m--;
            }
            if(s[i]=='D') d++;
            if(s[i]=='M') m++,dm+=d;
            if(s[i]=='C') ans+=dm;
            
        }
        cout<<ans<<"\n";
    }
}