#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   ll n,m;
   cin >> n >> m;
   if(n==1 || m==1)
   {
       int r = n*m;
       if(r>=2)cout << r-2 << endl;
       else cout << 1 << endl;
   }
   else
   {
       ll val = (n-2)*(m-2) ;
       //ll r = (n*2)+((m-2)*2);
       cout << val<< endl;
   }
}

