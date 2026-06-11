#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
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
    ll k,a,b,ans=0;
    cin>>k>>a>>b;
    if(a+1>=b) cout<<1+k;
    else{
        if(k<=a) cout<<1+k;
        else cout<<a+(k-a+1)/2*(b-a)+(k-a+1)%2;
    }
}