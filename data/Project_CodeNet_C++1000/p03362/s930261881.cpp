//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

bool prime (int i) {
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) return false;
    }
    return true;
}
int main()
{
    fast_io
    ll i,n,p,j,k;
    cin>>n;
    for(j=2; j<55555; j++)
    {
        if(n==0)
            break;
        if(prime(j)==true&&j%5==1)
        {
                cout<<j<<" ";
                n--;
        }
    }
    return 0;
}



