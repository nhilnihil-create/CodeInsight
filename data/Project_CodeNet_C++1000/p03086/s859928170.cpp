#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int ans=0,a=0;
    rep(i,s.size()){
        if(s[i]=='A'||s[i]=='C'||s[i]=='G'||s[i]=='T') a++;
        else a=0;
        ans=max(ans,a);
    }
    cout<<ans;
}