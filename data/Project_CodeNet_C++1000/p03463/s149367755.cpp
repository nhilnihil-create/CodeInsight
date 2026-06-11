#include<bits/stdc++.h>
#define lld long long int
#define pb push_back
#define in insert
#define mod 1000000007
#define pi 3.14159265358979

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    lld n,a,b;
    cin>>n>>a>>b;

    if((abs(a-b)-1)%2==0)cout<<"Borys"<<"\n";
    else cout<<"Alice"<<"\n";
}
