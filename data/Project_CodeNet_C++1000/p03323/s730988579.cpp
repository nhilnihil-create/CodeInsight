#include <bits/stdc++.h>
using namespace std;
int main()
{
       int a,b;cin>>a>>b;
       if(a>b)
        swap(a,b);
       int s=16-a*2;
       if(2*(b-a)<=s)
        cout<<"Yay!";
       else cout<<":(";
    return 0;
   }