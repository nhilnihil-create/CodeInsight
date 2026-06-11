#include <bits/stdc++.h>
using namespace std;
bitset<4000006> S;

int main()
{
    int i,n,x;
    cin >> n;
    S[0] = true;
    int sum = 0,rs=0;
    for(i=0;i<n;i++)
    {
        cin >> x;
        sum += x;
        S|=(S<<x);
    }
    rs = (sum+1)/2;
    for(i=rs;i<=sum;i++)
    {
        if(S[i])
            break;
    }
    cout << i << endl;
return 0;
}
