#include <bits/stdc++.h>
using namespace std;

int A,B,C,X,Y;
long long ans=1000000000;

int main(){
    cin>>A>>B>>C>>X>>Y;

    for (int i = 0; i <= 200000; i+=2)
    {
        long long a = max(0,X-i/2);
        long long b = max(0,Y-i/2);

        ans = min(ans, A*a + B*b + C*i);
    }
    cout << ans << endl;

    return 0;
}
