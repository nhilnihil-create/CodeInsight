#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll a,b,c,k,a1,b1,c1,cnt=0;
    cin>>a>>b>>c>>k;
    if(k%2==0)
        cout<<a-b;
    else
        cout<<b-a;
}