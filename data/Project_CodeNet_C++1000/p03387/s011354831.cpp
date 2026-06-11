#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int A,B,C,ans,M,x;
    cin >> A >> B >> C;

    M = max({A,B,C});

    for(int i = M;;i++){
        if((3*i)%2 == (A+B+C)%2){
            x = i;
            break;
        }
    }

    ans = (3*x-A-B-C)/2;

    cout << ans << endl;

    return 0;
}