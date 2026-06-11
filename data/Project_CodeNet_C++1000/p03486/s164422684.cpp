#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
#include<cmath>
#include<string>
#include<iomanip>
#include <numeric>
#include <limits>
const unsigned int M = 1000000007;
using namespace std;
 
int main()
{
string a,b,c,v; cin>>a>>b;
sort(a.begin(),a.end());
sort(b.begin(),b.end());
reverse(b.begin(),b.end());
if(a<b) cout<<"Yes";
else cout<<"No";
return 0;
}