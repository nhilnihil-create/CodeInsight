#include<bits/stdc++.h>
using namespace std;
int sumOfN(int n)
{
    int sum = 0;
    while(n!=0)
    {
        int  d = n%10;
        sum+=d;
        n/=10;
    }

    return sum;
}
int main()
{
    int n;
    cin>>n;


    if(n%sumOfN(n) == 0)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

