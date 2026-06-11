#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int a,b,c;
    cin>> a>>b>>c;

    string ans="No";

    if(a==b && b==c && c==a) ans="Yes";

    cout << ans << endl;

   return 0;
}