#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const int MOD = 1000000007;
const int INF = 1000000000;

int main()
{
   int a,b,c,d;
   cin >> a >> b >> c >> d;
   if((abs(a-b)<=d&&abs(b-c)<=d)||abs(a-c)<=d)
   {
      cout<<"Yes"<<endl;
   }
   else
   {
      cout<<"No"<<endl;
   }
   
   return 0;
}