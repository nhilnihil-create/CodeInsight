#include <iostream>
#include <iomanip>
using namespace std;
const  long INF = 1e9;
const  long MOD = 1e9 + 7;
#define repi(i,n,init) for(int i=init;i<int(n);i++)

int main()
{
    double t,x;
    cin >> t >> x;
    cout << fixed << setprecision(10) << t/x << endl;
    return 0;
}