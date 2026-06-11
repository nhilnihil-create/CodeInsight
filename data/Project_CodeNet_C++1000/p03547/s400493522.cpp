#include <bits/stdc++.h>
using namespace std;
char x,y;
int main()
{
    cin>>x>>y;
    if (x<y)
      cout<<"<";
    if (x>y)
      cout<<">";
    if (x==y)
      cout<<"=";
    return 0;
}