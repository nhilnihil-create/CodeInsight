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
int n,a; cin>>n>>a;
if(n-(n/500)*500 <= a) cout<<"Yes";
else cout<<"No";
return 0;
}