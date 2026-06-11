//ドワンゴからの挑戦状5-予選C
#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=a;i<n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll n,q,k;
string s;

int main(){
    cin>>n>>s>>q;

    while(q--){
        cin>>k;
        ll d=0,m=0,dm=0,ans=0;
        rep(i,n){
            if(s[i]=='D')d++;
            if(s[i]=='M')m++,dm+=d;
            if(s[i]=='C')ans+=dm;
            if(i>=k-1&&s[i-k+1]=='D')d--,dm-=m;
            if(i>=k-1&&s[i-k+1]=='M')m--;
        }
        cout<<ans<<endl;
    }
}