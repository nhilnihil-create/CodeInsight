#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

using namespace std;

int main ()
{
    string S;
    int res,cnt;

    cin >> S;
    
    cnt = 0;
    res = 0;
    REPI (S.size ())
    {
        if (S[i]=='A' || S[i] == 'T' || S[i] == 'G' || S[i] == 'C')
            cnt++;
        else{
            if (cnt > res)
                res = cnt;
            cnt = 0;
        }
    }
    
    if (cnt > res)
        res = cnt;
    
    cout << res << endl;
    return 0;
}