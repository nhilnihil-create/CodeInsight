#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b=1;
    cin>>a;
    while(b--)
    {
        long double c = sqrt(a);
        if(c-floor(c)==0)
            cout<<a<<endl;
        else
        {
            a--;
            b++;
        }
    }
    return 0;
}
