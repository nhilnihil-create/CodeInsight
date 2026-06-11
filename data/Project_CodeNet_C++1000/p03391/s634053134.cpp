#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, a[200009], b[200009];
vector<int> v1, v2;
ll sum, mx=2e9;
int main()
{
    IO
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]<b[i])
            v1.push_back(i);
        else if(a[i]>b[i])
            v2.push_back(i), mx=min(mx,1LL*b[i]);
        sum+=a[i];
    }
    if(v1.empty()&&v2.empty())
        return cout<< 0, 0 ;
    cout<<sum-mx;
    return 0;
}
