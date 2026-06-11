#include <bits/stdc++.h>
using namespace std;
int main()
{
    int D,N;
    cin >> D >> N;
    if(D==0)
    {
        if(!(N==100))
        {cout << N << endl;
        return 0;}
        else
        {
            cout << 101 <<endl;
            return 0;
        }
    }
    if(D==1)
    {  
        if(N==100)
        {
            cout << 10100<< endl;
            return 0;
        }
        cout << N*100 << endl;
        return 0;
    }
        if(N==100)
        {
            cout << 1010000 << endl;
            return 0;
        }
        cout << N*10000 << endl;
}
