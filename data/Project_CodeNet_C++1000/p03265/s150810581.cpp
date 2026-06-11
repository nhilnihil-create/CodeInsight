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
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    int x=x2-x1,y=y2-y1;
    cout<<x2-y<<" "<<y2+x<<" "<<x1-y<<" "<<y1+x<<endl;
}