//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int32_t main()
{
    IOS
    int n,m,d;
    cin>>n>>m>>d;
    cout<<fixed<<setprecision(12);
    if(d==0)
        cout<<(m-1)*1.0/n;
    else
        cout<<2.0*(m-1)*(n-d)/n/n;
}