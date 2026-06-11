#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b)      for(int i=a;i<=b;i++)
#define revp(i,b,a)     for(int i=b;i>=a;i--)

int n;
long double temp,sum=0;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    cin>>n;
    rep(i,1,n)
    {
        cin>>temp>>s;
        if(s=="BTC")
            sum+=temp*380000;
        else
            sum+=temp;
    }
    cout<<setprecision(20)<<sum;
}
