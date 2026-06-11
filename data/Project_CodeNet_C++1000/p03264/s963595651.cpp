#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
int n;
int main()
{	
   scanf("%d",&n);
   int e=0,o=0;
   if(n%2)e=1;
   e+=n/2;
   o+=n/2;
   cout<<e*o<<endl;
}