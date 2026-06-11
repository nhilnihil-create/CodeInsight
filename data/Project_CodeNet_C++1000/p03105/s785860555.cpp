#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int INF=1e9-5;

int main()
{
   int a,b,c;
   cin>>a>>b>>c;
   int m=b/a;
   if(m<=c)
    cout<<m<<endl;
   else
    cout<<c<<endl;
    return 0;
}