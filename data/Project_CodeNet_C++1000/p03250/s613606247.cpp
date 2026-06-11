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
    int i;
    int a[3];
    for (i=0;i<3;i++)
        cin>>a[i];
    sort(a,a+3,greater<int>());
    cout<<a[0]*10+a[1]+a[2]<<endl;
}
