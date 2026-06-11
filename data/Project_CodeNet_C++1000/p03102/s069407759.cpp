#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

using namespace std;

int main ()
{
    int N,M,res,C,b,a,sum;
    vector<int> B,bv;

    cin >> N >> M >> C;
    
    REPI (M)
    {
        cin >> b;
        B.push_back(b);
    }
    
    res = 0;
    
    REPI (N)
    {
        sum = 0;
        REPJ (M)
        {
            cin >> a;
            sum += a * B[j];
        }
        if (sum + C > 0)
            res++;
    }

    cout << res << endl;

    return 0;
}