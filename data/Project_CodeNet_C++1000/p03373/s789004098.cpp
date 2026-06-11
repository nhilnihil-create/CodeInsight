#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)

int main()
{
    int A,B,C,X,Y;
    cin >> A>>B>>C>>X>>Y;

    int mincost = INT_MAX;
    REP(z, max(X,Y)+1){
        int xnum = max(0, X-z);
        int ynum = max(0, Y-z);
        int cost = z*2*C+xnum*A+ynum*B;
        mincost = min(mincost, cost);
    }    

    cout << mincost << endl;


   return 0;
}