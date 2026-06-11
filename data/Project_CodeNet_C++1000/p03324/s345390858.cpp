#include <bits/stdc++.h>
using namespace std;

using str = string;
using ss = stringstream;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int d,n;
    cin>>d>>n;

    ss s;

    if(n==100)s<<101;
    else s<<n;
    
    for(int i=0;i<d;i++)s<<"00";

    cout<<s.str()<<"\n";

    return 0;
}
