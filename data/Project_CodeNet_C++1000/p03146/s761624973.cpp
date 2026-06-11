#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int s;
    cin>>s;

    int cnt=1;
    int n=s;

    while(!(n==4||n==2||n==1))
    {
        if(n%2)n=3*n+1;
        else n/=2;
        cnt++;
    }

    cnt+=3;

    cout<<cnt<<"\n";

    return 0;
}
