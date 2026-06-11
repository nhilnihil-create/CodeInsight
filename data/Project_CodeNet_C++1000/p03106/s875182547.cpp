#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,b,k,br=0;
    cin >> a >> b >> k;
    for (int i=min(a,b);i>=1;i--)
    {
        if(a%i==0 && b%i==0)
            br++;
        if(br==k)
        {
            cout << i;
            return 0;
        }
    }
}
