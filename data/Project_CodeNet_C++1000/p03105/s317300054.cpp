#include<bits/stdc++.h>
using namespace std;
int main()
{

      int a,b,c;
      cin>>a>>b>>c;
      if(a*c<=b)
        cout<<c<<endl;
      else if(b<a)
        cout<<'0'<<endl;
      else
        cout<<b/a<<endl;
        return 0;
}
