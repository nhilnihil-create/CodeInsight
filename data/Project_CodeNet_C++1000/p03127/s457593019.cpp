#include<bits/stdc++.h>
#define speed_up ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ara(A,N) sort(A,A+N)
#define rev(A,N) sort(A,A+N,greater<long long>())
using namespace std;
int main()
{
    speed_up;
    ll n, i;
    cin>>n;
    ll gcd = 0;
    while(n--)
    {
        cin>>i;
        gcd = __gcd(gcd, i);
    }
    cout<<gcd<<endl;

//peace

  return 0;
}