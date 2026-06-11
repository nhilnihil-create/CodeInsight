#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const long long MOD = 1e9 + 7;


#define INPUT(x)                freopen(x,"r",stdin)
#define OUTPUT(x)               freopen (x,"w",stdout)


#define pb                      push_back
#define endl                    '\n'
#define LCM(a,b)                (a/__gcd(a,b))*b
#define GCD(a,b)                __gcd(a,b)
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define PI                      acos(-1.0)
#define distance(x1,y1,x2,y2)   sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))
#define MAX                     1e9 + 9

#define taratari                ios_base::sync_with_stdio(0);cin.tie(NULL);


int main()
{
    taratari

    int n;
    cin>>n;

    int a[n];
    int b[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }

    int boro=0;

    for(int i=0;i<n;i++)
    {
       if(a[i]>b[i])
       {
           boro+=(a[i]-b[i]);
       }
    }

    cout<<boro;


    return 0;

}

