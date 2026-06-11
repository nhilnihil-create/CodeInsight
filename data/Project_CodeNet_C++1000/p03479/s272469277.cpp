#include<bits/stdc++.h>
#define ll long long
#define mod 838627288460106
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    fast_io
    ll x,y,i,j,cur,cnt=0;
    cin>>x>>y;
    cur=x;
    while(cur<=y)
    {
        cur=cur*2;
        cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}



