#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    int a, b, t;
    cin>>a>>b>>t;
    int total = 0;
    int time = 0;
    while(true)
    {
        time = time + a;
        if(time <= (t+0.5))
        {
            total = total + b;
            continue;
        }
        else break;
    }
    cout<<total;
    return 0;
}