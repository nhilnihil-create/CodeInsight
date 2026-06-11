/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,k;
    cin>>a>>b>>k;
    for(int i=100;i>=0;i--){
        if(a%i==0 && b%i==0)--k;
        if(k==0){cout<<i;return 0;}
    }
}
