#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){return b!=0?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

int main(){
    ll n;
    string s;
    cin>>n>>s;
    ll mn,cnt=0;
    for(ll i=1;i<n;i++){
        if(s[i]=='E') cnt++;
    }
    mn=cnt;
    for(ll i=1;i<n;i++){
        if(s[i]=='E') cnt--;
        if(s[i-1]=='W') cnt++;
        mn=min(mn,cnt); 
    }
    cout<<mn<<endl;
    return 0;
}