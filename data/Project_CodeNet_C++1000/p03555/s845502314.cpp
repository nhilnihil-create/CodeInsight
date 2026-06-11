#include <iostream>
#include <bits/c++io.h>
#include <algorithm>
#include <iomanip>
#include <math.h>
using namespace std;

int main()
{
string x,y;
cin>>x>>y;
reverse(x.begin(),x.end());
if(x==y)
    cout<<"YES"<<endl;
else
    cout<<"NO"<<endl;

 return 0;
}
