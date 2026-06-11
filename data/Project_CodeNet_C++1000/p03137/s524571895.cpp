/****************************************************************************************************
                                        SUBMITTED BY-

                                               aish_07

****************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define sl set<ll>
#define vs vector<string>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define PI  3.14159265
#define mod 998244353
int main()
{
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0;i<m;i++)
        cin>>a[i];

    sort(a,a+m);

    if(n>=m)
        cout<<"0\n";
    else
    {
        ll k=0;
        int b[m-1];
        for(int i=0;i<m-1;i++)
        {
            b[i]=a[i+1]-a[i];
        }
        sort(b,b+m-1);
        for(int i=0;i<m-n;i++)
            k+=b[i];
        cout<<k<<"\n";
    }
    return 0;
}
