#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,a,b,imin = 10000000,sum;
    cin >> N;

    for(int i = 1;i < N;i++){
        sum = 0;
        a = i;
        b = N-i;
        while(a > 0){
            sum += a%10;
            a /= 10;
        }
        while(b > 0){
            sum += b%10;
            b /= 10;
        }

        imin = min(imin,sum);

    }

    cout << imin << endl;

    return 0;
}
