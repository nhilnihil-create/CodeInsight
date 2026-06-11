#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,k;
    string s;
    cin>>n>>k>>s;
    s[k-1]=s[k-1]+32;
    cout<<s;
    return 0;


}
