#include <bits/stdc++.h>
#define ll long long
using namespace std;

//GCD,LCM
ll gcd(ll a, ll b){ return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b){ return a/gcd(a,b)*b;}

int main()
{
    double N,A[110]={},sum=0,d[110]={},ave,m=10000;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    }

    ave = sum/N;

    for(int i=0;i<N;i++){
        d[i] = abs(A[i]-ave);
        m = min(m,d[i]);
    }

    for(int i=0;i<N;i++){
        if(d[i] == m){
            cout<<i<<endl;
            return 0;
        }
    }

    return 0;
}