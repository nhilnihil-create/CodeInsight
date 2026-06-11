
#include<bits/stdc++.h>
using namespace std;
main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long i,j,k,l,m,n,o,p,q;
    while(cin>>m>>n)
    { i=m*n;
      i-=(m+n);
      i++;
      if(m==0||n==0)i=0;
      cout<<i<<endl;

    }
    return 0;
}
