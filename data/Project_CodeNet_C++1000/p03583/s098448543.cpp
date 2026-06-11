#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long gcd(long x, long y)
{    if (y == 0)
        return x;
    return gcd(y, x % y);}
long long lcm(long x, long y){ return x * y / gcd(x, y);}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}


int main()
{
    ll N;
    cin>>N;

    for(ll h=1;h<=3500;h++){
        for(ll n=1;n<=3500;n++){

            ll a=N*h*n;
            ll b=4*h*n - N*n - N*h;

            if(b!=0 && a%b==0 && a/b>0){
                cout<<h<<" "<<n<<" "<<a/b<<endl;
                return 0;
            }
        }
    }

    return 0;
}
