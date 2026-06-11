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
    int n;
    cin>>n;

    int l[n];
    for(int i=0;i<n;i++)
        cin>>l[i];
    sort(l,l+n);

    int sum=0;
    for(int i=0;i<n-1;i++)
        sum+=l[i];
    if(l[n-1]<sum)
        cout<<"Yes\n";
    else
      cout<<"No\n";
    return 0;
}
