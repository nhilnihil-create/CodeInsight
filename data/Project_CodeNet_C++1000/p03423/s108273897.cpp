#include <iostream>
#include <string>
#include <math.h>
using namespace std;
signed main()
{
    int N;
    cin >> N ;
    if(N<3)
        cout << 0 << endl;
    else
        cout << N/3 << endl;
}