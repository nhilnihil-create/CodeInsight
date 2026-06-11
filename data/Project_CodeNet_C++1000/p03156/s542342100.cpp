#include <bits/stdc++.h>
#define ll long long
using namespace std;

// GCD, LCM
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}
 
int main()
{
    int N,A,B,f=0,s=0,t=0,P;
    cin>>N>>A>>B;

    for(int i=1;i<=N;i++){
        cin>>P;
        if(P>=(B+1)){
            t++;
        }else if(P>=(A+1)&&P<=B){
            s++;
        }else{
            f++;
        }
    }

    cout<<min(f,min(s,t))<<endl;
 
    return 0;
}