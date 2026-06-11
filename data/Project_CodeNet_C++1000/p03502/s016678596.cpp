#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool HN(ll n)
{
    ll sum = 0;
    ll num = n;
    while(num){
        ll rem = num % 10;
    sum = sum + rem;
    num = num / 10;
    }
   // printf("%lld\n",sum);
   // printf("%lld\n",n);
    if(n % sum == 0)
        return true;

    return false;
}
int main()
{
    ll n;
    scanf("%lld",&n);

    ll res = HN(n);

    if(res == 1){
        printf("Yes\n");
    }
    else
        printf("No\n");

    return 0;
}
