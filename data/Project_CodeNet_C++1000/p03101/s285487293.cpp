#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
long long n,k,a,b;

void _case()
{
    cin>>n>>k>>a>>b;
    cout<<(n-a)*(k-b)<<'\n';
}

main()
{
    fastio();
    _case();

}

