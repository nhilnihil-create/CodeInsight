#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define M 1000000007
#define pb push_back
#define fs first
#define se second
using namespace std;
int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll t=min(a,b);
    ll u=max(a,b);
    if(t<c && c<u)
        cout<<"Yes";
    else
        cout<<"No";
    cout<<endl;

}
