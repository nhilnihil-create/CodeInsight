#include <bits/stdc++.h>
#define ll long long
using namespace std;

// GCD, LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
int main()
{
    int N,H,W,A,B,ans=0;
    cin>>N>>H>>W;

    for(int i=1;i<=N;i++){
        cin>>A>>B;
        if(A>=H&&B>=W)ans++;
    }

    cout<<ans<<endl;
 
    return 0;
}