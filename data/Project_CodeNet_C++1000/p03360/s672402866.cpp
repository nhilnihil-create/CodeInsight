#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int a[3],k;
    cin>>a[0]>>a[1]>>a[2];
    cin>>k;
    sort(a,a+3);
    cout<<a[0]+a[1]+a[2]*(1<<k)<<endl;
}