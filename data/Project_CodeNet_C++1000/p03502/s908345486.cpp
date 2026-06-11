#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int SumOfDigit(ll n)
{
    int sum=0;
    while(n)
        sum+=n%10,n/=10;
    return sum;
}

int main()
{
    ll n;
    cin>>n;
    int s=SumOfDigit(n);
    if(n%s)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}
