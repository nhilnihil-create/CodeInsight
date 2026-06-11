#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long LL;
int main()
{
    int n,k;

    cin >> n >> k;
    if(k==0)
    {
        cout << (LL)n*n << endl;
    }
    else
    {
        LL sum = 0;

        for(int i = k+1;i<=n;i++)
        {
            int b = i;

            sum+=n/b*(b-k);

            if(n%b>=k){
                sum+=n%b-k+1;
            }
        }

        cout << sum << endl;
    }


    return 0;
}
