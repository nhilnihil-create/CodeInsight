#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    int A;
    cin >> A;
    
    int cnt;
    while(A>0){
        int n = A%10;
        if (n==2) cnt++;
        A/=10;
    }
    cout << cnt << endl;

   return 0;
}