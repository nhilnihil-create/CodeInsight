#include <bits/stdc++.h>
using namespace std;
void fast(){
cin.tie(0);
cin.sync_with_stdio(0);
}
int main()
{
    fast();
 int a,b;
 cin>>a>>b;
for(int i=1;i<=3;i++)
{
   if((i*a*b)%2!=0)
    {cout<<"Yes";return 0;}
}
cout<<"No";
}
