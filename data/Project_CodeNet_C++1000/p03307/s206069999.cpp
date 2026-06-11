#include <bits/stdc++.h>
using namespace std;
#define int long long int

void test()
{
   int n;
   cin>>n;
   if(n%2==0)
   {
       cout<<n<<endl;
       return;
   }
   else
   {
       cout<<n*2<<endl;
   }
}
int32_t main()
{

    int t = 1;
    // cin >> t;
    while (t--)
    {
        test();
    }

    return 0;
}