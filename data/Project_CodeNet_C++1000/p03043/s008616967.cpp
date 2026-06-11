#include<iostream>
#include<math.h>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<stdlib.h>
#include<stack>
using namespace std;
#define PI 3.14159265358979
typedef  long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#include<set>
ll mod = 1000000007;
int main(void)
{
    ll n,k;
    cin>>n>>k;
    double pans=0;
    for(int i=1;i<=n;i++)
    {
        //i points
        ll a =0;
        while(1)
        {   
            if(i*pow(2,a)>=k) break;
            else a ++;


        }
        double p = pow(0.5,a);
        pans+=p;
    }

    pans/=n;

    cout<<setprecision(14)<<pans<<endl;

}