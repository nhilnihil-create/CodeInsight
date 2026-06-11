#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l1[10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll a=n,b=0;
    while(n>0){
        b+=n%10;
        n/=10;
    }
    if(a%b==0)cout<<"Yes";
    else cout<<"No";
}
