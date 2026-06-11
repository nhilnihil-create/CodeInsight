#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,flag=1;
    cin>>n;
    while(flag--)
    {
        long double sr = sqrt(n);
        if(sr-floor(sr)==0)
            cout<<n<<endl;
        else
        {
            n--;
            flag++;
        }
    }
    return 0;
}
