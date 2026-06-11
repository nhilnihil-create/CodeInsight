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
    ll n;
    cin>>n;
    double y=0.0;
    ll j;string s;
    for(int i=1;i<=n;i++){double b=1.0;
        cin>>b>>s;
        if(s=="BTC")b=(b*380000.0);
        y+=b;
    }
    cout<<fixed<<setprecision(8)<<y;
}
