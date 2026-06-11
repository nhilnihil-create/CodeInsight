#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,a[3],b;
    for(i=0;i<3;i++)
    {
        cin >> a[i];
    }
    sort(a,a+3);

    b=abs(a[2]-a[1])+abs(a[1]-a[0]);
    cout<<b<<endl;
    return 0;
}