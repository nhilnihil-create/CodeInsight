#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll fn(int n)
{
    if(n==0)return 2;
    else if(n==1)return 1;
    else return fn(n-1)+fn(n-2);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    //cout<<fn(n);
    if(n==0)cout<<2;
    else if(n==1)cout<<1;
    else{
        ll c=0,a=2,b=1;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;b=c;
        }
        cout<<c;
    }
}
