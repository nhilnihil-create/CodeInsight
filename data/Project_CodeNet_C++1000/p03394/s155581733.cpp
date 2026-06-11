#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
//1000000000000223
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<int> v[8];
int n;
void solve(int i, int d)
{
    n-=d;
    while(d--)
        cout<<v[i].back()<<" ", v[i].pop_back();
}
int main()
{
    IO
    cin>>n;
    for(int i=1; i<=3e4; i++)
        v[i%6].push_back(i);
    if(n==3)
        return cout<<"2 5 63", 0 ;
    cout<<v[2].back()<<" "<<v[4].back()<<" "<<v[3].back()<<" ";
    v[2].pop_back();
    v[4].pop_back();
    v[3].pop_back();
    cout<<v[3].back()<<" ";
    v[3].pop_back();
    n-=4;
    while(n>=3&&v[2].size()>=3)
        solve(2,3);

    while(n>=3&&v[4].size()>=3)
        solve(4,3);
    if(n>=2)
        solve(2,1), solve(4,1);
    while(n>=2&&v[3].size()>=2)
        solve(3,2);

    while(n)
        solve(0,1);
    return 0;
}
