#include<bits/stdc++.h>
using namespace std ;

// #define int long long
#define endl '\n'
int32_t main()
{

   int a,b;
   cin>>a>>b;
   int ans=0;
   if(a>b)
   	{ans+=a;a--;
   	}
   	else
   	{
   		ans+=b;
   		b--;
   	}
   	ans+=max(a,b);
   	cout<<ans;
   	return 0;
}
