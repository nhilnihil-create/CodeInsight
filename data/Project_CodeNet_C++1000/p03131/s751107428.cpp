#include <bits/stdc++.h>
using namespace std;

int main(void) 
{
    long long K,A,B;
    cin >> K >> A >> B;

    long long ans;

    if (B-A<=2)
        ans=K+1;
    else
    {
        long long c=(K-(A-1))/2;
        if (c<0) c=0;
        ans=K+1-2*c+(B-A)*c;
    }

    cout << ans << endl;

    return 0;
}
