#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int x,y,z;
    cin>>x>>y>>z;
    if (x<y&&z<y&&z>x)
        cout<<"Yes";
    else if (x>y &&z>y&&z<x)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
