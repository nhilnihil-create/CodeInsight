#include "bits/stdc++.h"
#include<cmath>

using namespace std;
typedef long long li;

const li mod = 998244353;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    li n,m;
    cin>>n>>m;
    int r = n*m;
    if(r%2==0){cout<<"Even"<<"\n";}
    else {cout<<"Odd"<<"\n";}

    return 0;

}

