#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{

      int n;
      cin>>n;
      ll a[n];
      ll sum=0,mn=0;
      for(int i=0;i<n;i++){
            cin>>a[i];
            mn=__gcd(mn,a[i]);
      }
      cout<<mn<<endl;

}
