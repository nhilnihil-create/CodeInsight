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
    int n,a,b,i;
    cin>>n;
    cin>>a>>b;
    int p,mark[3]={0};
    for (i=0;i<n;i++)
    {
        cin>>p;
        if (p<=a)
            mark[0]++;
        else if (p>=(a+1) && p<=b)
            mark[1]++;
        else
            mark[2]++;
    }
    cout<<min({mark[0],mark[1],mark[2]})<<endl;
}