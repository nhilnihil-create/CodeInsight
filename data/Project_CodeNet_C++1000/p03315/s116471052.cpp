#include <bits/stdc++.h>
#define ll long long
using namespace std;

// GCD, LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main()
{
    int ans=0;
    string S;
    cin>>S;

    for(int i=0;i<S.length();i++){
        if(S[i]=='+'){ans++;}
        else{ans--;}
    }

    cout<<ans<<endl;

    return 0;
}