/****************************************************************************************************
                                        SUBMITTED BY-

                                                AISH_07

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

int n,k;
cin>>n>>k;
ll a[n];
for(int i=0;i<n;i++)
    cin>>a[i];

sort(a,a+n);

ll mini=LONG_MAX;

for(int i=n-1;i-k+1>=0;i--)
    mini=min(a[i]-a[i-k+1],mini);


cout<<mini<<"\n";
return 0;
}
