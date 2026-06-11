#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, b, t, candy=0;
    cin>>x>>b>>t;
    int time=x;
    while(time<=t)
    {
        candy+=b;
        time+=x;
    }
    cout<<candy;
}
