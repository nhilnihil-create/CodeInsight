#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main()
{
     ll n,i,j,s=0,x;
     cin>>n;
     for(i=0;i<n;i++)
     {
         cin>>x;
         s+=x;
     }
     cout<<s-n<<endl;
    return 0;
}


