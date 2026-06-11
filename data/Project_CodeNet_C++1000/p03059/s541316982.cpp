///**PEACE AND MERCY BE UPON YOU**\\\

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MOD = 1e9 + 7;

//********FILE READ AND WRITE*************************\\

#define INPUT(x)                freopen(x,"r",stdin)
#define OUTPUT(x)               freopen (x,"w",stdout)

//----------------------------------------------------\\

#define pb                      push_back
#define endl                    '\n'
#define LCM(a,b)                (a/__gcd(a,b))*b
#define GCD(a,b)                __gcd(a,b)
#define SP(x,y)                 fixed<<setprecision((y))<<(x)
#define PI                      acos(-1.0)
#define distance(x1,y1,x2,y2)   sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1))

#define taratari                ios_base::sync_with_stdio(0);cin.tie(NULL);


///**********************************************************************************\\\


int main()
{
    taratari

    int x,b,t;
    cin>>x>>b>>t;

    if(x>t)
    {
        cout<<"0";
        return 0;
    }

    int sum=0,i=2;

    int start=x;

    while(start<=t)
    {
      sum+=b;
      start=x*i;
      i++;
    }

    cout<<sum;



    return 0;
}

