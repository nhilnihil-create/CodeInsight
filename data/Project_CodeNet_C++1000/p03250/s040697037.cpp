#include<bits/stdc++.h>
using namespace std;
int main()
{
    int d[4],i;
    for(i=0;i<3;i++)
        cin>>d[i];
    sort(d,d+3,greater<int>());
    cout<<(d[0]*10+d[1])+d[2]<<endl;
}
