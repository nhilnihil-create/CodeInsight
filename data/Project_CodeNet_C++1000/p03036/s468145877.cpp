#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long r,d,x[20];
    cin>>r>>d>>x[0];
    for(int i=1;i<11;i++)
    {
        x[i] = r*x[i-1]-d;
        cout<<x[i]<<endl;
    }
}
