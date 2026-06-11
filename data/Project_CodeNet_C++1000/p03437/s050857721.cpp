#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,Q;
    cin >> N >>Q;
    int64_t ans=-1;
    if(N==Q||Q==1)
    {
        cout << ans <<endl;
    }
    else
    {
        int co=1;
        ans=N;
        bool chk=true;
        while (chk)
        {
            if(!(ans%Q==0))
            {
                chk=false;
            }
            else
            {
                co++;
                ans=ans*co;
            } 
            if(abs(ans)>1e18)
            {
                cout << -1 <<endl;
                return 0;
            }
        }
        cout << ans << endl;
    }
}

