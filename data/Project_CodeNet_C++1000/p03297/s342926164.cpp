#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll T;
ll A, B, C, D;

ll gcd(ll p, ll q)
{
    if(q == 0) return p;
    else return gcd(q, p % q);
}

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>A>>B>>C>>D;
        if(A < B || D < B)
        {
            cout<<"No"<<endl;
            continue;
        }
        ll g = gcd(D, B);
        if((C + g - A % g) / g * g + A % g < B)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
