#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int a[maxn*4];
int vis[maxn*4];
int b[maxn*4];
int main()
{
   int a,b;
   cin>>a>>b;
   if(a+b==15) cout<<"+"<<endl;
   else if(a*b==15) cout<<"*"<<endl;
   else cout<<"x"<<endl;
    return 0;
}
