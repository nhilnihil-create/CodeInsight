#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int a , b, k;

    cin>>a>>b>>k;
    for(int i=a;i<= min(a+k-1 , b) ;i++)
    {
        cout<<i<<"\n";
    }
    for(int i= max(a+k,b-k+1 );i<=b;i++)
        cout<<i<<"\n";
}