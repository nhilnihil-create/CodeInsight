#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;

int main(){
    ll n,cnt=0,sum=0,ans;
    string s;
    cin>>s;
    n=s.size();
    rep(i,n){
        if(s[i]=='B'){
            cnt++;
            sum+=n-i;
        }
    }
    ans=sum-cnt*(cnt+1)/2;
    cout<<ans;
}