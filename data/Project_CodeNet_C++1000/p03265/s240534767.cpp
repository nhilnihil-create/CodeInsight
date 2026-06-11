#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d;
    cin>>a>>b>>c>>d;

    cout<<c-(d-b)<<" "<<d+(c-a)<<" "<<c-(d-b)-(c-a)<<" "<<d+(c-a)-(d-b);
}
