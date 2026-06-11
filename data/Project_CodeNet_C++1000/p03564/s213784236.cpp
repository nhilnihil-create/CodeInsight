#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
using namespace std;
 
int main()
{
int n,k,m=1; cin>>n>>k;
for(int i=0;i<n;i++)
{
    if(m<k) m*=2;
    else m+=k;
 
}
cout<<m;
return 0;
}