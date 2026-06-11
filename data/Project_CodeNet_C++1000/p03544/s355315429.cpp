#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;

int main()
{
 long long n,n0=2,n1=1,number;
 cin>>n;
 if(n==1) cout<<1;
 else{
 for(int i=0;i<=n-2;i++)
 {
     number=n0+n1;
     n0=n1;
     n1=number;
 }
 cout<<number;
 }
 return 0;
}
